#include "stream_channel_input_ansi_clear_line.h"

namespace stream::channel::input::ansi::clear
{

Line::Line(Pointer & pointer) : _pointer(pointer)
{

}

Line::~Line()
{

}

Line & Line::right()
{
    pointer_input(_pointer, "%s", "\e[K");

    return *this;
}

Line & Line::left()
{
    pointer_input(_pointer, "%s", "\e[1K");

    return *this;
}

Line & Line::entire()
{
    pointer_input(_pointer, "%s", "\e[2K");

    return *this;
}


}; /* namespace: stream::channel::input::ansi::clear */
