#include "stream_input_ansi_clear_line.h"

namespace stream::input::ansi::clear
{

Line::Line(Pointer & pointer) : _pointer(pointer)
{

}

Line::~Line()
{

}

Line & Line::right()
{
    Pointer::input(_pointer, "%s", "\e[K");

    return *this;
}

Line & Line::left()
{
    Pointer::input(_pointer, "%s", "\e[1K");

    return *this;
}

Line & Line::entire()
{
    Pointer::input(_pointer, "%s", "\e[2K");

    return *this;
}


}; /* namespace: stream::input::ansi::clear */
