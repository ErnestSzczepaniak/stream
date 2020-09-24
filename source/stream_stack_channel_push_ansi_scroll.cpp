#include "stream_stack_channel_push_ansi_scroll.h"

namespace stream::stack::channel::push::ansi
{

Scroll::Scroll(Pointer & pointer) : Channel(pointer)
{

}

Scroll::~Scroll()
{

}

Scroll & Scroll::up()
{
    _input_format("%s", "\eD");

    return *this;
}

Scroll & Scroll::down()
{
    _input_format("%s", "\eM");

    return *this;
}

}; /* namespace: stream::stack::channel::push::ansi */
