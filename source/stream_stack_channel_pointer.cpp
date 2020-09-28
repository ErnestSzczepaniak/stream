#include "stream_stack_channel_pointer.h"
#include "tools_string.h"

namespace stream::stack::channel
{

Pointer::Pointer(char * start, char * stop)
: 
_start(start), 
_stop(stop),
_current(start),
_limit(stop)
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

Pointer & Pointer::limit(char * value)
{
    _limit = value;

    return *this;
}

char * Pointer::limit()
{
    return _limit;
}

Pointer & Pointer::position(int value)
{
    if (value >= 0 && _start + value < _stop && _start + value < _limit) 
        _current = _start + value;

    return *this;
}

int Pointer::position()
{
    return (_current - _start);
}

int Pointer::span()
{
    return (_stop - _start);
}

Pointer & Pointer::save()
{
    _stash[0] = _start;    
    _stash[1] = _stop;
    _stash[2] = _current;
    _stash[3] = _limit;

    return *this;
}

Pointer & Pointer::restore()
{
    _start = _stash[0];
    _stop = _stash[1];
    _current = _stash[2];
    _limit = _stash[3];

    return *this;
}

Pointer & Pointer::reset()
{
    _current = _start;
    _limit = _stop;

    return *this;
}

Pointer & Pointer::move(int value)
{
    if (_current + value >= _start && _current + value < _stop && _current + value < _limit) 
        _current += value;

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

/* ---------------------------------------------| info |--------------------------------------------- */

}; /* namespace: stream::stack::channel */