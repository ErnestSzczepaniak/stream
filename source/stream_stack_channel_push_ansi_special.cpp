#include "stream_stack_channel_push_ansi_special.h"

namespace stream::stack::channel::push::ansi
{

Special::Special(Pointer & pointer) : Channel(pointer)
{

}

Special::~Special()
{

}

Special & Special::a()
{
    _input_format("%s", "\a");

    return *this;
}

Special & Special::b()
{
    _input_format("%s", "\b");

    return *this;
}

Special & Special::r()
{
    _input_format("%s", "\r");

    return *this;
}

Special & Special::n()
{
    _input_format("%s", "\n");

    return *this;
}

Special & Special::t()
{
    _input_format("%s", "\t");

    return *this;
}

Special & Special::v()
{
    _input_format("%s", "\v");

    return *this;
}

Special & Special::f()
{
    _input_format("%s", "\f");

    return *this;
}

}; /* namespace: stream::stack::channel::push::ansi */
