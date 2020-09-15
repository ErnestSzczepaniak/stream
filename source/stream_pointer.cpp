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

Pointer & Pointer::position(int value)
{
    if (value >= 0 && value < _size) _current = _start + value;

    return *this;
}

int Pointer::position()
{
    return (_current - _start);
}

Pointer & Pointer::reset()
{
    _current = _start;

    return *this;
}

Pointer::operator char *()
{
    return _current;
}

char Pointer::operator*()
{
    return *_current;
}

Pointer & Pointer::operator++(int)
{
    return _move(1);
}

Pointer & Pointer::operator--(int)
{
    return _move(-1);
}

Pointer & Pointer::operator+=(int value)
{
    return _move(value);
}

Pointer & Pointer::operator-=(int value)
{
    return _move(-value);
}

Pointer & Pointer::operator=(char * value)
{
    _current = value;

    return *this;
}

Pointer & Pointer::operator=(Pointer & other)
{
    _current = other._current;
    _size = other._size;
    _start = other._start;

    return *this;
}

char * Pointer::output(Pointer & pointer, int word, const char * delimiters)
{
    using namespace tools::string;

    auto * ptr = get::word(pointer, word, delimiters);

    if (ptr == nullptr) return nullptr;

    auto size_word = get::size(ptr, " ");

    pointer += (size_word + get::size((char *) delimiters));

    return ptr;
}

/* ---------------------------------------------| info |--------------------------------------------- */

Pointer & Pointer::_move(int value)
{
    if (_current + value >= _start && _current + value < _start + _size) _current += value;

    return *this;
}


}; /* namespace: stream */
