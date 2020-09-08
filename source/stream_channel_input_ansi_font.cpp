#include "stream_channel_input_ansi_font.h"

namespace stream::channel::input::ansi
{

Font::Font(Pointer & pointer) : _pointer(pointer)
{
    
}

Font::~Font()
{
    
}

Font & Font::bold(bool value)
{
    if (value) pointer_input(_pointer, "%s", "\e[1m");
    else pointer_input(_pointer, "%s", "\e[21m");

    return *this;
}

Font & Font::faint(bool value)
{
    if (value) pointer_input(_pointer, "%s", "\e[2m");
    else pointer_input(_pointer, "%s", "\e[22m");

    return *this;
}

Font & Font::italic(bool value)
{
    if (value) pointer_input(_pointer, "%s", "\e[3m");
    else pointer_input(_pointer, "%s", "\e[23m");

    return *this;
}

Font & Font::underline(bool value)
{
    if (value) pointer_input(_pointer, "%s", "\e[4m");
    else pointer_input(_pointer, "%s", "\e[24m");

    return *this;
}

Font & Font::blink(bool value)
{
    if (value) pointer_input(_pointer, "%s", "\e[5m");
    else pointer_input(_pointer, "%s", "\e[25m");

    return *this;
}

Font & Font::reverse(bool value)
{
    if (value) pointer_input(_pointer, "%s", "\e[7m");
    else pointer_input(_pointer, "%s", "\e[27m");

    return *this;
}

Font & Font::invisible(bool value)
{
    if (value) pointer_input(_pointer, "%s", "\e[8m");
    else pointer_input(_pointer, "%s", "\e[28m");

    return *this;
}

Font & Font::crossed(bool value)
{
    if (value) pointer_input(_pointer, "%s", "\e[9m");
    else pointer_input(_pointer, "%s", "\e[29m");

    return *this;
}

Font & Font::reset()
{
    pointer_input(_pointer, "%s", "\e[m");

    return *this;
}

}; /* namespace: stream::channel::input::ansi */
