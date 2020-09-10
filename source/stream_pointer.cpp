#include "stream_pointer.h"

namespace stream
{

Pointer::Pointer(char * start, int size)
:
_start(start),
_current(start),
_size(size)
{

}

Pointer::~Pointer()
{

}

char * Pointer::start()
{
    return _start;
}

char * Pointer::stop()
{
    return (_start + _size);
}

char * Pointer::end()
{
    return (_start + tools::string::get::size(_start));
}

char * Pointer::current()
{
    return _current;
}

int Pointer::size_stop()
{
    return (_size);
}

int Pointer::size_end()
{
    return (end() - start());
}

int Pointer::size_current()
{
    return (_current - _start);
}

bool Pointer::is_aligned()
{
    return (size_current() == size_end());
}

Pointer & Pointer::move_start()
{
    _current = _start;

    return *this;
}

Pointer & Pointer::move_stop()
{
    _current = stop();

    return *this;
}

Pointer & Pointer::move_end()
{
    _current = end();

    return *this;
}

Pointer & Pointer::move(int value)
{
    if ((_current + value >= _start) && (_current + value < (_start + _size))) _current += value;

    return *this;
}

}; /* namespace: stream */