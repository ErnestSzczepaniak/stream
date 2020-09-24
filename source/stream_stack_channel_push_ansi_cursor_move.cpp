#include "stream_stack_channel_push_ansi_cursor_move.h"

namespace stream::stack::channel::push::ansi::cursor
{

Move::Move(Pointer & pointer) : Channel(pointer)
{

}

Move::~Move()
{

}

Move & Move::home()
{
    _input_format("%s", "\e[H");

    return *this;
}

Move & Move::up(int value)
{
    _input_format("\e[%dA", value);

    return *this;
}

Move & Move::down(int value)
{
    _input_format("\e[%dB", value);

    return *this;
}

Move & Move::right(int value)
{
    _input_format("\e[%dC", value);

    return *this;
}

Move & Move::left(int value)
{
    _input_format("\e[%dD", value);

    return *this;
}

Move & Move::down_start(int value)
{
    _input_format("\e[%dE", value);

    return *this;
}

Move & Move::up_start(int value)
{
    _input_format("\e[%dF", value);

    return *this;
}

Move & Move::column(int value)
{
    _input_format("\e[%dG", value);

    return *this;
}

Move & Move::at(int x, int y)
{
    _input_format("\e[%d;%dH", y + 1, x + 1);

    return *this;
}

}; /* namespace: stream::chastack::nnel::set::pushnsi::cursor */
