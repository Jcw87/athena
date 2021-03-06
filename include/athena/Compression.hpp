#pragma once

#include "athena/Types.hpp"

namespace athena::io::Compression {
// Zlib compression
atInt32 decompressZlib(const atUint8* src, atUint32 srcLen, atUint8* dst, atUint32 dstLen);
atInt32 compressZlib(const atUint8* src, atUint32 srcLen, atUint8* dst, atUint32 dstLen);

#if AT_LZOKAY
// lzo compression
atInt32 decompressLZO(const atUint8* source, atInt32 sourceSize, atUint8* dst, atInt32& dstSize);
#endif

// Yaz0 encoding
atUint32 yaz0Decode(const atUint8* src, atUint8* dst, atUint32 uncompressedSize);
atUint32 yaz0Encode(const atUint8* src, atUint32 srcSize, atUint8* data);

atUint32 decompressLZ77(const atUint8* src, atUint32 srcLen, atUint8** dst);
atUint32 compressLZ77(const atUint8* src, atUint32 srcLen, atUint8** dst, bool extended = false);
} // namespace athena::io::Compression
