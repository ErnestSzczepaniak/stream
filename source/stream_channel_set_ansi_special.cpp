#include "stream_channel_set_ansi_special.h"

namespace stream::channel::set::ansi
{

Special::Special(Pointer & pointer) : _pointer(pointer)
{

}

Special::~Special()
{

}

Special & Special::a()
{
    _pointer.input("%s", "\a");

    return *this;
}

Special & Special::b()
{
    _pointer.input("%s", "\b");

    return *this;
}

Special & Special::r()
{
    _pointer.input("%s", "\r");

    return *this;
}

Special & Special::n()
{
    _pointer.input("%s", "\n");

    return *this;
}

Special & Special::t()
{
    _pointer.input("%s", "\t");

    return *this;
}

Special & Special::v()
{
    _pointer.input("%s", "\v");

    return *this;
}

Special & Special::f()
{
    _pointer.input("%s", "\f");

    return *this;
}

}; /* namespace: stream::channel::set::ansi */
