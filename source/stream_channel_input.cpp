#include "stream_channel_input.h"

Stream_channel_input & Stream_channel_input::integer(int value)
{
    return format("%d", value);
}

Stream_channel_input & Stream_channel_input::text(const char * value)
{
    return format("%s", value);
}