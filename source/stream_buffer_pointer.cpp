#include "stream_buffer_pointer.h"

Stream_buffer_pointer::Stream_buffer_pointer(char * pointer)
:
_initial(pointer),
_current(pointer)
{

}

char * Stream_buffer_pointer::get()
{
    return _current;
}

Stream_buffer_pointer & Stream_buffer_pointer::set(char * value)
{
    _current = value;

    return *this;
}

int Stream_buffer_pointer::position()
{
    return (_current - _initial);
}

Stream_buffer_pointer & Stream_buffer_pointer::position(int value)
{
    _current = _initial + value;

    return *this;
}

Stream_buffer_pointer & Stream_buffer_pointer::reset()
{
    _current = _initial;

    return *this;
}

Stream_buffer_pointer & Stream_buffer_pointer::move(int value)
{
    _current += value;

    return *this;
}

