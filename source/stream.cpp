#include "stream.h"

Stream::Stream() : output(_buffer, size_buffer), input(_buffer, size_buffer)
{

}

Stream::~Stream()
{

}

char * Stream::buffer()
{
    return _buffer;
}

int Stream::size_actual()
{
    return tools::string::get::size(_buffer);
}

Stream & Stream::reset()
{
    output.pointer.reset();
    input.pointer.reset();

    memset(_buffer, 0, size_buffer);

    return *this;
}

Stream & Stream::name(const char * value)
{
    _name = value;
    
    return *this;
}

const char * Stream::name()
{
    return _name;
}

Stream & Stream::operator=(Stream & other)
{
    input.pointer = other.input.pointer;
    output.pointer = other.output.pointer;

    memcpy(_buffer, other._buffer, other.size_actual());

    return *this;
}