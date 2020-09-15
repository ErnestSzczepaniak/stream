#include "stream_input_ansi_clear_display.h"

namespace stream::input::ansi::clear
{

Display::Display(Pointer & pointer) : _pointer(pointer)
{

}

Display::~Display()
{

}

Display & Display::right()
{
    Pointer::input(_pointer, "%s", "\e[J");

    return *this;
}

Display & Display::left()
{
    Pointer::input(_pointer, "%s", "\e[1J");

    return *this;
}

Display & Display::entire()
{
    Pointer::input(_pointer, "%s", "\e[2J");

    return *this;
}

}; /* namespace: stream::input::ansi::clear */
