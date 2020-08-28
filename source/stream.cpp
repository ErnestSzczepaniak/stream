#include "stream.h"

Stream::Stream()
{
    input.buffer(&_buffer);

    input.pointer.initial(_buffer.address());
    input.pointer.current(_buffer.address());

    output.buffer(&_buffer);

    output.pointer.initial(_buffer.address());
    output.pointer.current(_buffer.address());

}