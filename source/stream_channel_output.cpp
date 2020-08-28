#include "stream_channel_output.h"
#include <iostream>
#include "string.h"

int Stream_channel_output::integer(int word)
{
    return std::stoi(pointer.initial());
}

/* ---------------------------------------------| info |--------------------------------------------- */

void Stream_channel_output::_point_word(int word)
{
    pointer.reset();

}