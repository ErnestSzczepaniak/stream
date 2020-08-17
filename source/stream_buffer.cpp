#include "stream_buffer.h"
#include "string.h"

Stream_buffer::Stream_buffer()
:
pointer_read(_buffer),
pointer_write(_buffer)
{
    memset(_buffer, 0, _size);
}

char * Stream_buffer::start()
{
    return &_buffer[0];
}

char * Stream_buffer::end()
{
    return &_buffer[_size - 1];
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

bool Stream_buffer::is_empty()
{
    return (size_actual() == 0);
}

bool Stream_buffer::is_full()
{
    return (size_actual() == _size);
}

Stream_buffer & Stream_buffer::reset()
{
    memset(_buffer, 0, _size);
}

Stream_buffer & Stream_buffer::fill(char value)
{
    memset(_buffer, value, _size);
}

int Stream_buffer::read(char * buffer, int size)
{
    auto result = 0;

    if (pointer_read.position() + size <= size_actual()) result = size;
    else if (pointer_read.position() + size > size_actual()) result = size_actual() - pointer_read.position();

    memcpy(buffer, pointer_read.get(), result);
    pointer_read.move(result);

    return result;
}

int Stream_buffer::write(char * buffer, int size)
{
    auto result = 0;

    if (pointer_write.position() + size <= size_max()) result = size;
    else if (pointer_write.position() + size > size_max()) result = size_max() - pointer_write.position();

    memcpy(pointer_write.get(), buffer, size);

    pointer_write.move(size);

    return result;
}
