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
    Pointer::input(_pointer, "%s", "\a");

    return *this;
}

Special & Special::b()
{
    Pointer::input(_pointer, "%s", "\b");

    return *this;
}

Special & Special::r()
{
    Pointer::input(_pointer, "%s", "\r");

    return *this;
}

Special & Special::n()
{
    Pointer::input(_pointer, "%s", "\n");

    return *this;
}

Special & Special::t()
{
    Pointer::input(_pointer, "%s", "\t");

    return *this;
}

Special & Special::v()
{
    Pointer::input(_pointer, "%s", "\v");

    return *this;
}

Special & Special::f()
{
    Pointer::input(_pointer, "%s", "\f");

    return *this;
}

}; /* namespace: stream::input::ansi */
