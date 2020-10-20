#include "stream_stack_channel_push.h"

namespace stream::stack::channel
{

Push::Push(char * start, char * stop) : pointer(start, stop), Channel(pointer), ansi(pointer)
{

}

Push::~Push()
{

}

Push & Push::decimal(unsigned int value, const char * delimiters)
{
    _input_format("%d%s", value, delimiters);

    return *this;
}

Push & Push::hexadecimal(unsigned int value, int digits, const char * delimiters)
{
    _input_format("0x%0*x%s", digits, value, delimiters);

    return *this;
}

Push & Push::floating(float value, int digits, const char * delimiters)
{
    _input_format("%.*f%s", digits, value, delimiters);

    return *this;
}

Push & Push::character(char value, const char * delimiters)
{
    _input_format("%c%s", value, delimiters);

    return *this;
}

Push & Push::word(char * value, const char * delimiters)
{
    auto size = tools::string::get::size(value, delimiters);

    _input_format("%.*s", size, value);

    return *this;
}

Push & Push::text(char * value, const char * delimiters)
{
    auto size = tools::string::get::size(value, delimiters);

    _input_format("%.*s", size, value);

    return *this;
}

Push & Push::data(void * data, int size)
{
    _input_data(data, size);

    return *this;
}


}; /* namespace: stream::channel::action */
