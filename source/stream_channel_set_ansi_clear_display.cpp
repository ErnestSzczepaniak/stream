#include "stream_channel_set_ansi_clear_display.h"

namespace stream::channel::set::ansi::clear
{

Display::Display(Pointer & pointer) : _pointer(pointer)
{

}

Display::~Display()
{

}

Display & Display::right()
{
    _pointer.input("%s", "\e[J");

    return *this;
}

Display & Display::left()
{
    _pointer.input("%s", "\e[1J");

    return *this;
}

Display & Display::entire()
{
    _pointer.input("%s", "\e[2J");

    return *this;
}

}; /* namespace: stream::channel::set::ansi::clear */
