#include "stream_stack_channel_push_ansi_cursor.h"

namespace stream::stack::channel::push::ansi
{

Cursor::Cursor(Pointer & pointer) : Channel(pointer), move(pointer)
{

}

Cursor::~Cursor()
{

}

Cursor & Cursor::save()
{
    _input_format("%s", "\e[s");

    return *this;
}

Cursor & Cursor::restore()
{
    _input_format("%s", "\e[u");

    return *this;
}

Cursor & Cursor::show()
{
    _input_format("%s", "\e[?25h");

    return *this;
}

Cursor & Cursor::hide()
{
    _input_format("%s", "\e[?25l");

    return *this;
}

}; /* namespace: stream::stack::channel::push::ansi */


