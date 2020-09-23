#include "stream_channel_pointer.h"
#include "tools_string.h"

namespace stream::channel
{

Pointer::Pointer(char * start, char * stop) : _start(start), _stop(stop), _current(start)
{

}

Pointer::~Pointer()
{

}

Pointer & Pointer::start(char * value)
{
    _start = value;

    return *this;
}

char * Pointer::start()
{
    return _start;
}

Pointer & Pointer::stop(char * value)
{
    _stop = value;

    return *this;
}

char * Pointer::stop()
{
    return _stop;
}

Pointer & Pointer::current(char * value)
{
    _current = value;

    return *this;
}

char * Pointer::current()
{
    return _current;
}

Pointer & Pointer::reset()
{
    _current = _start;

    return *this;
}

Pointer & Pointer::save()
{
    _stash[0] = _start;
    _stash[1] = _stop;
    _stash[2] = _current;

    return *this;
}

Pointer & Pointer::restore()
{
    _start = _stash[0];
    _stop = _stash[1];
    _current = _stash[2];

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
    if (value >= 0 && (_start + value) < _stop) _current = _start + value;

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
    _current = _start + (other._current - other._start);
    _stop = _start + (other._stop - other._start);

    return *this;
}

char * Pointer::output(const char * delimiters)
{
    auto size = tools::string::get::size(_current, delimiters);

    auto * ptr = _current;

    _move(size + 1);

    return ptr;
}

/* ---------------------------------------------| info |--------------------------------------------- */

Pointer & Pointer::_move(int value)
{
    if (_current + value >= _start && _current + value < _stop) _current += value;

    return *this;
}


}; /* namespace: stream::channel::action */