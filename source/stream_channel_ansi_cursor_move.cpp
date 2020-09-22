#include "stream_channel_set_ansi_cursor_move.h"

namespace stream::channel::set::ansi::cursor
{

Move::Move(Pointer & pointer) : _pointer(pointer)
{

}

Move::~Move()
{

}

Move & Move::home()
{
    _pointer.input("%s", "\e[H");

    return *this;
}

Move & Move::up(int value)
{
    _pointer.input("\e[%dA", value);

    return *this;
}

Move & Move::down(int value)
{
    _pointer.input("\e[%dB", value);

    return *this;
}

Move & Move::right(int value)
{
    _pointer.input("\e[%dC", value);

    return *this;
}

Move & Move::left(int value)
{
    _pointer.input("\e[%dD", value);

    return *this;
}

Move & Move::down_start(int value)
{
    _pointer.input("\e[%dE", value);

    return *this;
}

Move & Move::up_start(int value)
{
    _pointer.input("\e[%dF", value);

    return *this;
}

Move & Move::column(int value)
{
    _pointer.input("\e[%dG", value);

    return *this;
}

Move & Move::at(int x, int y)
{
    _pointer.input("\e[%d;%dH", y + 1, x + 1);

    return *this;
}

}; /* namespace: stream::channel::set::ansi::cursor */
