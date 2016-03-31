#ifndef STREAM_HPP
#define STREAM_HPP

#include "Global.hpp"

namespace athena
{
namespace io
{
std::ostream& operator<<(std::ostream& os, Endian& endian);

class IStream
{
public:
    IStream() : m_hasError(false) {}
    virtual ~IStream() {}

    virtual void setEndian(Endian)    = 0;
    virtual Endian endian()      const = 0;
    virtual bool isBigEndian()   const = 0;
    virtual bool isLittleEndian()const = 0;
    virtual void seek(atInt64, SeekOrigin) = 0;
    virtual bool atEnd()         const = 0;
    virtual atUint64 position()    const = 0;
    virtual atUint64 length()      const = 0;
    bool hasError() const { return m_hasError; }
protected:
    void setError() { m_hasError = true; }
    bool m_hasError;
};
}
}
#endif // STREAM_HPP