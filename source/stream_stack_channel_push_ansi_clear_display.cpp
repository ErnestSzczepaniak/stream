#include "stream_stack_channel_push_ansi_clear_display.h"

namespace stream::stack::channel::push::ansi::clear
{

Display::Display(Pointer & pointer) : Channel(pointer)
{

}

Display::~Display()
{

}

Display & Display::right()
{
    _input_format("%s", "\e[J");

    return *this;
}

Display & Display::left()
{
    _input_format("%s", "\e[1J");

    return *this;
}

Display & Display::entire()
{
    _input_format("%s", "\e[2J");

    return *this;
}

}; /* namespace: stream::stack::channel::push::ansi::clear */
