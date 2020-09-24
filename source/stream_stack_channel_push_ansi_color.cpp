#include "stream_stack_channel_push_ansi_color.h"

namespace stream::stack::channel::push::ansi
{

Color::Color(Pointer & pointer) : Channel(pointer)
{

}

Color::~Color()
{

}

Color & Color::foreground(int r, int g, int b)
{
    _input_format("\e[38;2;%d;%d;%dm", r, g, b);

    return *this;
}   

Color & Color::background(int r, int g, int b)
{
    _input_format("\e[48;2;%d;%d;%dm", r, g, b);

    return *this;
}

}; /* namespace: stream::stack::channel::push::ansi */
