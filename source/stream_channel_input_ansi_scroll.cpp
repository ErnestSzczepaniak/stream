#include "stream_channel_input_ansi_scroll.h"

namespace stream::channel::input::ansi
{

Scroll::Scroll(Pointer & pointer) : _pointer(pointer)
{

}

Scroll::~Scroll()
{

}

Scroll & Scroll::up()
{
    pointer_input(_pointer, "%s", "\eD");

    return *this;
}

Scroll & Scroll::down()
{
    pointer_input(_pointer, "%s", "\eM");

    return *this;
}

}; /* namespace: stream::channel::input::ansi */
