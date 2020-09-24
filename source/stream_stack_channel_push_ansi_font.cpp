#include "stream_stack_channel_push_ansi_font.h"

namespace stream::stack::channel::push::ansi
{

Font::Font(Pointer & pointer) : Channel(pointer)
{
    
}

Font::~Font()
{
    
}

Font & Font::bold(bool value)
{
    if (value) _input_format("%s", "\e[1m");
    else _input_format("%s", "\e[21m");

    return *this;
}

Font & Font::faint(bool value)
{
    if (value) _input_format("%s", "\e[2m");
    else _input_format("%s", "\e[22m");

    return *this;
}

Font & Font::italic(bool value)
{
    if (value) _input_format("%s", "\e[3m");
    else _input_format("%s", "\e[23m");

    return *this;
}

Font & Font::underline(bool value)
{
    if (value) _input_format("%s", "\e[4m");
    else _input_format("%s", "\e[24m");

    return *this;
}

Font & Font::blink(bool value)
{
    if (value) _input_format("%s", "\e[5m");
    else _input_format("%s", "\e[25m");

    return *this;
}

Font & Font::reverse(bool value)
{
    if (value) _input_format("%s", "\e[7m");
    else _input_format("%s", "\e[27m");

    return *this;
}

Font & Font::invisible(bool value)
{
    if (value) _input_format("%s", "\e[8m");
    else _input_format("%s", "\e[28m");

    return *this;
}

Font & Font::crossed(bool value)
{
    if (value) _input_format("%s", "\e[9m");
    else _input_format("%s", "\e[29m");

    return *this;
}

Font & Font::reset()
{
    _input_format("%s", "\e[m");

    return *this;
}

}; /* namespace: stream::stack::channel::push::ansi */
