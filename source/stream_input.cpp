#include "stream_input.h"

namespace stream
{

Input::Input(char * buffer, int size) : Channel(buffer, size), ansi(pointer)
{

}

Input & Input::character(char value, const char * delimiters)
{
    Pointer::input(pointer, "%c%s", value, delimiters);

    return *this;
}

Input & Input::word(char * value, const char * delimiters)
{
    Pointer::input(pointer, "%s%s", value, delimiters);

    return *this;
}

Input & Input::text(char * value, const char * delimiters)
{
    Pointer::input(pointer, "%s%s", value, delimiters);

    return *this;
}

}; /* namespace: stream */