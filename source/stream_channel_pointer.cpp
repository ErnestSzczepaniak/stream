#include "stream_channel_pointer.h"
#include "tools_string.h"

namespace stream::channel
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

Pointer & Pointer::reset()
{
    _current = _start;

    return *this;
}

int Pointer::offset_end()
{
    return tools::string::get::size(_current);
}

bool Pointer::is_aligned()
{
    return (*_current == 0);
}

Pointer & Pointer::align_end()
{
    _current += offset_end();

    return *this;
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
    position(other.position());

    return *this;
}

char * Pointer::output(int word, const char * delimiters)
{
    auto * ptr = tools::string::get::word(_current, word, delimiters);

    if (ptr == nullptr) return nullptr;

    auto size_word = tools::string::get::size(ptr, " ");

    _current += (size_word + tools::string::get::size((char *) delimiters));

    return ptr;
}

/* ---------------------------------------------| info |--------------------------------------------- */

Pointer & Pointer::_move(int value)
{
    if (_current + value >= _start && _current + value < _start + _size) _current += value;

    return *this;
}


}; /* namespace: stream::channel::action */