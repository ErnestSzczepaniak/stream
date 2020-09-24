#include "stream_stack_channel_push_ansi.h"

namespace stream::stack::channel::push
{

Ansi::Ansi(Pointer & pointer)
:
Channel(pointer),
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
    _input_format("%s", "\ec");

    return *this;
}

Ansi & Ansi::size(int x, int y) 
{
    _input_format("\e[8;%d;%dt", y, x);

    return *this;
}

Ansi & Ansi::minimize()
{
    _input_format("%s", "\e[2t");

    return *this;
}

Ansi & Ansi::maximize()
{
    _input_format("%s", "\e[1t");

    return *this;
}

}; /* namespace: stream:::channel::set */
