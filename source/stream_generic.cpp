#include "stream_generic.h"
#include "string.h"

Stream_generic::Stream_generic()
{
    memset(_buffer, 0, _size);

    pointer.initial(_buffer);
    pointer.current(_buffer);
}

char Stream_generic::at(int position)
{
    return _buffer[position];
}

Stream_generic & Stream_generic::at(int position, char value)
{
    _buffer[position] = value;

    return *this;
}

int Stream_generic::size_actual()
{
    return strlen(_buffer);
}

int Stream_generic::size_max()
{
    return _size;
}

int Stream_generic::size_remaining()
{
    return (_size - size_actual());
}

bool Stream_generic::is_empty()
{
    return (size_actual() == 0);
}

bool Stream_generic::is_full()
{
    return (size_actual() == _size);
}

Stream_generic & Stream_generic::clear()
{
    memset(_buffer, 0, _size);
}