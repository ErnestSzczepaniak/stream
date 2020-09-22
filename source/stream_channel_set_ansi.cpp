#include "stream_channel_set_ansi.h"

namespace stream::channel::set
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
    _pointer.input("%s", "\ec");

    return *this;
}

Ansi & Ansi::size(int x, int y) 
{
    _pointer.input("\e[8;%d;%dt", y, x);

    return *this;
}

Ansi & Ansi::minimize()
{
    _pointer.input("%s", "\e[2t");

    return *this;
}

Ansi & Ansi::maximize()
{
    _pointer.input("%s", "\e[1t");

    return *this;
}

}; /* namespace: stream:::channel::set */
