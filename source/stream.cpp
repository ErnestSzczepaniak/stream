#include "stream.h"

Stream::Stream() : output(buffer, size_buffer), input(buffer, size_buffer), find(buffer, size_buffer)
{
    reset();
}

Stream::~Stream()
{

}

int Stream::size_max()
{
    return size_buffer;
}

int Stream::size_actual()
{
    return tools::string::get::size(buffer);
}

Stream & Stream::reset()
{
    output.pointer.reset();
    input.pointer.reset();
    find.pointer.reset();

    memset(buffer, 0, size_buffer);

    return *this;
}

Stream & Stream::operator=(Stream & other)
{
    input.pointer = other.input.pointer;
    output.pointer = other.output.pointer;

    memcpy(buffer, other.buffer, size_buffer);

    return *this;
}

bool Stream::operator==(Stream & other)
{
    return tools::string::compare::equality(buffer, other.buffer);
}

bool Stream::operator!=(Stream & other)
{
    return !(*this == other);
}