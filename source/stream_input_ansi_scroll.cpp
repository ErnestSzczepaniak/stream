#include "stream_input_ansi_scroll.h"

namespace stream::input::ansi
{

Scroll::Scroll(Pointer & pointer) : _pointer(pointer)
{

}

Scroll::~Scroll()
{

}

Scroll & Scroll::up()
{
    Pointer::input(_pointer, "%s", "\eD");

    return *this;
}

Scroll & Scroll::down()
{
    Pointer::input(_pointer, "%s", "\eM");

    return *this;
}

}; /* namespace: stream::input::ansi */
