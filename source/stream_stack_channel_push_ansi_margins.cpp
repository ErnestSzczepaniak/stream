#include "stream_stack_channel_push_ansi_margins.h"

namespace stream::stack::channel::push::ansi
{

Margins::Margins(Pointer & pointer) : Channel(pointer)
{

}

Margins::~Margins()
{

}

Margins & Margins::horizontal(int from, int to)
{
    _input_format("\e[%d;%dr", from + 1, to + 1);

    return *this;
}

Margins & Margins::vertical(int from, int to)
{
    _input_format("\e[?69h\e[%d;%ds", from + 1, to + 1);

    return *this;
}

}; /* namespace: stream::stack::channel::push::ansi */
