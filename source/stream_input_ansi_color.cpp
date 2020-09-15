#include "stream_input_ansi_color.h"

namespace stream::input::ansi
{

Color::Color(Pointer & pointer) : _pointer(pointer)
{

}

Color::~Color()
{

}

Color & Color::foreground(int r, int g, int b)
{
    Pointer::input(_pointer, "\e[38;2;%d;%d;%dm", r, g, b);

    return *this;
}   

Color & Color::background(int r, int g, int b)
{
    Pointer::input(_pointer, "\e[48;2;%d;%d;%dm", r, g, b);

    return *this;
}

}; /* namespace: stream::input::ansi */
