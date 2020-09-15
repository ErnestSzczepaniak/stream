#include "stream_input_ansi_cursor_move.h"

namespace stream::input::ansi::cursor
{

Move::Move(Pointer & pointer) : _pointer(pointer)
{

}

Move::~Move()
{

}

Move & Move::home()
{
    Pointer::input(_pointer, "%s", "\e[H");

    return *this;
}

Move & Move::up(int value)
{
    Pointer::input(_pointer, "\e[%dA", value);

    return *this;
}

Move & Move::down(int value)
{
    Pointer::input(_pointer, "\e[%dB", value);

    return *this;
}

Move & Move::right(int value)
{
    Pointer::input(_pointer, "\e[%dC", value);

    return *this;
}

Move & Move::left(int value)
{
    Pointer::input(_pointer, "\e[%dD", value);

    return *this;
}

Move & Move::down_start(int value)
{
    Pointer::input(_pointer, "\e[%dE", value);

    return *this;
}

Move & Move::up_start(int value)
{
    Pointer::input(_pointer, "\e[%dF", value);

    return *this;
}

Move & Move::column(int value)
{
    Pointer::input(_pointer, "\e[%dG", value);

    return *this;
}

Move & Move::at(int x, int y)
{
    Pointer::input(_pointer, "\e[%d;%dH", y + 1, x + 1);

    return *this;
}

}; /* namespace: stream::input::ansi::cursor */
