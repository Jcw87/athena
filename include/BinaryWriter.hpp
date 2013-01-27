#ifndef __BINARYWRITER_HPP__
#define __BINARYWRITER_HPP__

#include "Stream.hpp"
#include <string>

/*! \class BinaryWriter
 *
 *  A Class for writing binary data to a file or memory stream,
 *  all work is done using a memory buffer, and not written directly to the disk
 *  this allows for fast, flexible code as well as the ability to quickly modify data
 *  \sa Stream
 */
class BinaryWriter : public Stream
{
public:
    BinaryWriter(const Uint8* data, Uint64 length);
    BinaryWriter(const Stream& stream);
    BinaryWriter(const std::string& filename);
    void save(const std::string& filename="");

    void writeInt16(Int16);
    void writeUInt16(Uint16);
    void writeInt32(Int32);
    void writeUInt32(Uint32);
    void writeInt64(Int64);
    void writeUInt64(Uint64);
    void writeFloat(float);
    void writeDouble(double);
    void writeBool(bool);
    void writeUnicode(const std::string& str);
private:
    Int8 readByte();
    Int8* readBytes(Int64);
    bool isOpenForReading();
    std::string m_filename;
};

#endif
