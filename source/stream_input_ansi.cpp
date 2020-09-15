#include "stream_input_ansi.h"

namespace stream::input
{

Ansi::Ansi(Pointer & pointer) 
:
_pointer(pointer),
clear(pointer), 
cursor(pointer), 
margins(pointer), 
scroll(pointer), 
font(pointer),
color(pointer),
special(pointer)
{

}

Ansi::~Ansi()
{

}

Ansi & Ansi::reset()
{
    Pointer::input(_pointer, "%s", "\ec");

    return *this;
}

Ansi & Ansi::size(int x, int y) 
{
    Pointer::input(_pointer, "\e[8;%d;%dt", y, x);

    return *this;
}

Ansi & Ansi::minimize()
{
    Pointer::input(_pointer, "%s", "\e[2t");

    return *this;
}

Ansi & Ansi::maximize()
{
    Pointer::input(_pointer, "%s", "\e[1t");

    return *this;
}

}; /* namespace: stream:::input */
