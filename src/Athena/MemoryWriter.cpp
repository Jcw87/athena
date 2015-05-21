// This file is part of libAthena.
//
// libAthena is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// libAthena is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with libAthena.  If not, see <http://www.gnu.org/licenses/>

#include "Athena/MemoryWriter.hpp"
#include "Athena/IOException.hpp"
#include "Athena/InvalidOperationException.hpp"
#include "Athena/InvalidDataException.hpp"
#include "Athena/FileNotFoundException.hpp"
#include "utf8.h"

#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>

#ifdef HW_RVL
#include <malloc.h>
#endif // HW_RVL

namespace Athena
{
namespace io
{

MemoryWriter::MemoryWriter(atUint8* data, atUint64 length)
    : m_data((atUint8*)data),
      m_length(length),
      m_position(0),
      m_bitPosition(0),
      m_endian(Endian::LittleEndian),
      m_progressCallback(nullptr)
{
    if (!m_data && m_length > 0)
        m_data = new atUint8[m_length];
}

MemoryWriter::MemoryWriter(const std::string& filename, std::function<void(int)> progressFun)
    : m_length(0),
      m_filepath(filename),
      m_position(0),
      m_bitPosition(0),
      m_endian(Endian::LittleEndian),
      m_progressCallback(progressFun)
{
    m_length = 0x10;
    m_bitPosition = 0;
    m_position = 0;
    m_data = new atUint8[m_length];

    if (!m_data)
        THROW_IO_EXCEPTION("Could not allocate memory!");

    memset(m_data, 0, m_length);
}

MemoryWriter::~MemoryWriter()
{
    delete[] m_data;
    m_data = nullptr;
}

void MemoryWriter::setEndian(Endian endian)
{
    m_endian = endian;
}

Endian MemoryWriter::endian() const
{
    return m_endian;
}

bool MemoryWriter::isBigEndian() const
{
    return (m_endian == Endian::BigEndian);
}

bool MemoryWriter::isLittleEndian() const
{
    return (m_endian == Endian::LittleEndian);
}

bool MemoryWriter::isOpen() const
{
    return m_data != nullptr;
}

void MemoryWriter::seek(atInt64 position, SeekOrigin origin)
{
    switch (origin)
    {
        case SeekOrigin::Begin:
            if (position < 0)
                THROW_IO_EXCEPTION("Position outside stream bounds");

            if ((atUint64)position > m_length)
                resize(position);

            m_position = position;
            break;

        case SeekOrigin::Current:
            if ((((atInt64)m_position + position) < 0))
                THROW_IO_EXCEPTION("Position outside stream bounds");

            if (m_position + position > m_length)
                resize(m_position + position);

            m_position += position;
            break;

        case SeekOrigin::End:
            if (((atInt64)m_length - position) < 0)
                THROW_IO_EXCEPTION("Position outside stream bounds");

            if ((atUint64)position > m_length)
                resize(position);

            m_position = m_length - position;
            break;
    }
}

bool MemoryWriter::atEnd() const
{
    return m_position >= m_length;
}

atUint64 MemoryWriter::position() const
{
    return m_position;
}

atUint64 MemoryWriter::length() const
{
    return m_length;
}

void MemoryWriter::setFilepath(const std::string& filepath)
{
    m_filepath = filepath;
}

std::string MemoryWriter::filepath() const
{
    return m_filepath;
}

void MemoryWriter::setData(const atUint8* data, atUint64 length)
{
    if (m_data)
        delete[] m_data;

    m_data = (atUint8*)data;
    m_length = length;
    m_position = 0;
    m_bitPosition = 0;
}

atUint8* MemoryWriter::data() const
{
    atUint8* ret = new atUint8[m_length];
    memset(ret, 0, m_length);
    memcpy(ret, m_data, m_length);
    return ret;
}


void MemoryWriter::save(const std::string& filename)
{
    if (!isOpen())
        THROW_INVALID_OPERATION_EXCEPTION("File not open for writing");

    if (filename.empty() && m_filepath.empty())
        THROW_INVALID_OPERATION_EXCEPTION("No file specified, cannot save.");

    if (!filename.empty())
        m_filepath = filename;

    FILE* out = fopen(m_filepath.c_str(), "wb");

    if (!out)
        THROW_FILE_NOT_FOUND_EXCEPTION(m_filepath);

    atUint64 done = 0;
    atUint64 blocksize = BLOCKSZ;

    do
    {
        if (blocksize > m_length - done)
            blocksize = m_length - done;

        atInt64 ret = fwrite(m_data + done, 1, blocksize, out);

        if (ret < 0)
            THROW_IO_EXCEPTION("Error writing data to disk");
        else if (ret == 0)
            break;

        done += blocksize;
    }
    while (done < m_length);

    fclose(out);
}

void MemoryWriter::seekBit(int bit)
{
    if (bit < 0 || bit > 7)
        THROW_INVALID_OPERATION_EXCEPTION("bit out of range");

    m_bitPosition = bit;
}

void MemoryWriter::writeBit(bool val)
{
    if (!isOpen())
        resize(sizeof(atUint8));

    if (m_position + sizeof(atUint8) > m_length)
        resize(m_position + sizeof(atUint8));

    if (val)
        *(atUint8*)(m_data + m_position) |= (1 << m_bitPosition);
    else
        *(atUint8*)(m_data + m_position) &= ~(1 << m_bitPosition);

    m_bitPosition++;

    if (m_bitPosition > 7)
    {
        m_bitPosition = 0;
        m_position += sizeof(atUint8);
    }
}

void MemoryWriter::writeUByte(atUint8 val)
{
    if (!isOpen())
        resize(sizeof(atUint8));

    if (m_bitPosition > 0)
    {
        m_bitPosition = 0;
        m_position += sizeof(atUint8);
    }

    if (m_position + 1 > m_length)
        resize(m_position + 1);

    *(atUint8*)(m_data + m_position) = val;

    m_position++;
}

void MemoryWriter::writeByte(atInt8 val)
{
    writeUByte(val);
}

void MemoryWriter::writeUBytes(atUint8* data, atUint64 length)
{
    if (!isOpen())
        resize(sizeof(atUint8) * length);

    if (m_bitPosition > 0)
    {
        m_bitPosition = 0;
        m_position += sizeof(atUint8);
    }

    if (!data)
        THROW_INVALID_DATA_EXCEPTION("data cannnot be NULL");

    if (m_position + length > m_length)
        resize(m_position + length);

    memcpy((atInt8*)(m_data + m_position), data, length);

    m_position += length;
}

void MemoryWriter::writeBytes(atInt8* data, atUint64 length)
{
    writeUBytes((atUint8*)data, length);
}

void MemoryWriter::writeInt16(atInt16 val)
{
    if (!isOpen())
        resize(sizeof(atInt16));

    if (m_bitPosition > 0)
    {
        m_bitPosition = 0;
        m_position += sizeof(atUint8);
    }

    if (m_position + sizeof(atInt16) > m_length)
        resize(m_position + sizeof(atInt16));

    if (isBigEndian())
        utility::BigInt16(val);
    else
        utility::LittleInt16(val);

    *(atInt16*)(m_data + m_position) = val;
    m_position += sizeof(atInt16);
}

void MemoryWriter::writeUint16(atUint16 val)
{
    writeInt16(val);
}

void MemoryWriter::writeInt32(atInt32 val)
{
    if (!isOpen())
        resize(sizeof(atInt32));

    if (m_bitPosition > 0)
    {
        m_bitPosition = 0;
        m_position += sizeof(atUint8);
    }

    if (m_position + sizeof(atInt32) > m_length)
        resize(m_position + sizeof(atInt32));

    if (isBigEndian())
        utility::BigInt32(val);
    else
        utility::LittleInt32(val);

    *(atInt32*)(m_data + m_position) = val;
    m_position += sizeof(atInt32);
}

void MemoryWriter::writeUint32(atUint32 val)
{
    writeInt32(val);
}

void MemoryWriter::writeInt64(atInt64 val)
{
    if (!isOpen())
        resize(sizeof(atInt64));

    if (m_bitPosition > 0)
    {
        m_bitPosition = 0;
        m_position += sizeof(atUint8);
    }

    if (m_position + sizeof(atInt64) > m_length)
        resize(m_position + sizeof(atInt64));


    if (isBigEndian())
        utility::BigInt64(val);
    else
        utility::LittleInt64(val);

    *(atInt64*)(m_data + m_position) = val;
    m_position += sizeof(atInt64);
}

void MemoryWriter::writeUint64(atUint64 val)
{
    writeInt64(val);
}

void MemoryWriter::writeFloat(float val)
{
    if (!isOpen())
        resize(sizeof(float));

    if (m_bitPosition > 0)
    {
        m_bitPosition = 0;
        m_position += sizeof(atUint8);
    }

    if (m_position + sizeof(float) > m_length)
        resize(m_position + sizeof(float));

    if (isBigEndian())
        utility::BigFloat(val);
    else
        utility::LittleFloat(val);


    *(float*)(m_data + m_position) = val;
    m_position += sizeof(float);
}

void MemoryWriter::writeDouble(double val)
{
    if (!isOpen())
        resize(sizeof(double));

    if (m_bitPosition > 0)
    {
        m_bitPosition = 0;
        m_position += sizeof(atUint8);
    }

    if (m_position + sizeof(double) > m_length)
        resize(m_position + sizeof(double));

    if (isBigEndian())
        utility::BigDouble(val);
    else
        utility::LittleDouble(val);

    *(double*)(m_data + m_position) = val;
    m_position += sizeof(double);
}

void MemoryWriter::writeBool(bool val)
{
    if (m_bitPosition > 0)
    {
        m_bitPosition = 0;
        m_position += sizeof(atUint8);
    }

    if (m_position + sizeof(bool) > m_length)
        resize(m_position + sizeof(bool));

    *(bool*)(m_data + m_position) = val;
    m_position += sizeof(bool);
}

void MemoryWriter::writeUnicode(const std::string& str)
{
    std::string tmpStr = "\xEF\xBB\xBF" + str;

    std::vector<short> tmp;

    utf8::utf8to16(tmpStr.begin(), tmpStr.end(), back_inserter(tmp));

    for (atUint16 chr : tmp)
    {
        if (chr != 0xFEFF)
            writeInt16(chr);
    }

    writeInt16(0);
}

void MemoryWriter::writeString(const std::string& str)
{
    for (atUint8 c : str)
    {
        writeUByte(c);

        if (c == '\0')
            break;
    }

    writeUByte(0);
}

void MemoryWriter::fill(atUint8 val, atUint64 length)
{
    while ((length--) > 0)
        writeUByte(val);
}

void MemoryWriter::fill(atInt8 val, atUint64 length)
{
    fill((atUint8)val, length);
}

void MemoryWriter::setProgressCallback(std::function<void (int)> cb)
{
    m_progressCallback = cb;
}

void MemoryWriter::resize(atUint64 newSize)
{
    if (newSize < m_length)
        THROW_INVALID_OPERATION_EXCEPTION("Stream::resize() -> New size cannot be less to the old size.");

    // Allocate and copy new buffer
    atUint8* newArray = new atUint8[newSize];
    memset(newArray, 0, newSize);

    if (m_data)
    {
        memcpy(newArray, m_data, m_length);

        // Delete the old one
        delete[] m_data;
    }

    // Swap the pointer and size out for the new ones.
    m_data = newArray;
    m_length = newSize;
}

} // io
} // Athena
