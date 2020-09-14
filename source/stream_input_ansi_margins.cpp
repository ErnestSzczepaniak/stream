#include "stream_input_ansi_margins.h"

namespace stream::input::ansi
{

Margins::Margins(Pointer & pointer) : _pointer(pointer)
{

}

Margins::~Margins()
{

}

Margins & Margins::horizontal(int from, int to)
{
    pointer_input(_pointer, "\e[%d;%dr", from + 1, to + 1);

    return *this;
}

Margins & Margins::vertical(int from, int to)
{
    pointer_input(_pointer, "\e[?69h\e[%d;%ds", from + 1, to + 1);

    return *this;
}

}; /* namespace: stream::input::ansi */
