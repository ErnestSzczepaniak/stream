#include "stream_channel_input_ansi_cursor.h"

namespace stream::channel::input::ansi
{

Cursor::Cursor(Pointer & pointer) : _pointer(pointer), move(pointer)
{

}

Cursor::~Cursor()
{

}

Cursor & Cursor::save()
{
    pointer_input(_pointer, "%s", "\e[s");

    return *this;
}

Cursor & Cursor::restore()
{
    pointer_input(_pointer, "%s", "\e[u");

    return *this;
}

Cursor & Cursor::show()
{
    pointer_input(_pointer, "%s", "\e[?25h");

    return *this;
}

Cursor & Cursor::hide()
{
    pointer_input(_pointer, "%s", "\e[?25l");

    return *this;
}

}; /* namespace: stream::channel::input::ansi */


