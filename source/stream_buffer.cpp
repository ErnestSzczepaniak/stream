#include "stream_buffer.h"
#include "string.h"

char * Stream_buffer::address()
{
    return _buffer;
}

char Stream_buffer::at(int position)
{
    return _buffer[position];
}

Stream_buffer & Stream_buffer::at(int position, char value)
{
    _buffer[position] = value;

    return *this;
}

int Stream_buffer::size_actual()
{
    return strlen(_buffer);
}

int Stream_buffer::size_max()
{
    return _size;
}

int Stream_buffer::size_remaining()
{
    return (_size - size_actual());
}

bool Stream_buffer::is_empty()
{
    return (size_actual() == 0);
}

bool Stream_buffer::is_full()
{
    return (size_actual() == _size);
}

Stream_buffer & Stream_buffer::clear()
{
    memset(_buffer, 0, _size);
}