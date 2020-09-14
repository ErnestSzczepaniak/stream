#include "stream_input_ansi_special.h"

namespace stream::input::ansi
{

Special::Special(Pointer & pointer) : _pointer(pointer)
{

}

Special::~Special()
{

}

Special & Special::a()
{
    pointer_input(_pointer, "%s", "\a");

    return *this;
}

Special & Special::b()
{
    pointer_input(_pointer, "%s", "\b");

    return *this;
}

Special & Special::r()
{
    pointer_input(_pointer, "%s", "\r");

    return *this;
}

Special & Special::n()
{
    pointer_input(_pointer, "%s", "\n");

    return *this;
}

Special & Special::t()
{
    pointer_input(_pointer, "%s", "\t");

    return *this;
}

Special & Special::v()
{
    pointer_input(_pointer, "%s", "\v");

    return *this;
}

Special & Special::f()
{
    pointer_input(_pointer, "%s", "\f");

    return *this;
}

}; /* namespace: stream::input::ansi */
