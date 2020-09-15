#include "stream_input_ansi_cursor.h"

namespace stream::input::ansi
{

Cursor::Cursor(Pointer & pointer) : _pointer(pointer), move(pointer)
{

}

Cursor::~Cursor()
{

}

Cursor & Cursor::save()
{
    Pointer::input(_pointer, "%s", "\e[s");

    return *this;
}

Cursor & Cursor::restore()
{
    Pointer::input(_pointer, "%s", "\e[u");

    return *this;
}

Cursor & Cursor::show()
{
    Pointer::input(_pointer, "%s", "\e[?25h");

    return *this;
}

Cursor & Cursor::hide()
{
    Pointer::input(_pointer, "%s", "\e[?25l");

    return *this;
}

}; /* namespace: stream::input::ansi */


