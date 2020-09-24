#include "stream_stack_channel_push_ansi_clear_line.h"

namespace stream::stack::channel::push::ansi::clear
{

Line::Line(Pointer & pointer) : Channel(pointer)
{

}

Line::~Line()
{

}

Line & Line::right()
{
    _input_format("%s", "\e[K");

    return *this;
}

Line & Line::left()
{
    _input_format("%s", "\e[1K");

    return *this;
}

Line & Line::entire()
{
    _input_format("%s", "\e[2K");

    return *this;
}

}; /* namespace: stream::stack::channel::push::ansi::clear */
