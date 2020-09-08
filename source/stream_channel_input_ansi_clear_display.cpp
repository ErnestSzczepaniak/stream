#include "stream_channel_input_ansi_clear_display.h"

namespace stream::channel::input::ansi::clear
{

Display::Display(Pointer & pointer) : _pointer(pointer)
{

}

Display::~Display()
{

}

Display & Display::right()
{
    pointer_input(_pointer, "%s", "\e[J");

    return *this;
}

Display & Display::left()
{
    pointer_input(_pointer, "%s", "\e[1J");

    return *this;
}

Display & Display::entire()
{
    pointer_input(_pointer, "%s", "\e[2J");

    return *this;
}

}; /* namespace: stream::channel::input::ansi::clear */
