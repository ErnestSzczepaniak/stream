#include "stream_channel_input_ansi.h"

namespace stream::channel::input
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
    pointer_input(_pointer, "%s", "\ec");

    return *this;
}

Ansi & Ansi::size(int x, int y) 
{
    pointer_input(_pointer, "\e[8;%d;%dt", y, x);

    return *this;
}

Ansi & Ansi::minimize()
{
    pointer_input(_pointer, "%s", "\e[2t");

    return *this;
}

Ansi & Ansi::maximize()
{
    pointer_input(_pointer, "%s", "\e[1t");

    return *this;
}


}; /* namespace: stream::channel::input */
