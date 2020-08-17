#include "stream_pointer.h"

char * Stream_pointer::initial()
{
    return _initial;
}

Stream_pointer & Stream_pointer::initial(char * value)
{
    _initial = value;

    return *this;
}

char * Stream_pointer::current()
{
    return _current;
}

Stream_pointer & Stream_pointer::current(char * value)
{
    _current = value;

    return *this;
}

int Stream_pointer::position()
{
    return (_current - _initial);
}

Stream_pointer & Stream_pointer::position(int value)
{
    _current = _initial + value;

    return *this;
}

Stream_pointer & Stream_pointer::reset()
{
    _current = _initial;

    return *this;
}

Stream_pointer & Stream_pointer::move(int value)
{
    _current += value;

    return *this;
}

