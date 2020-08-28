#include "stream_channel.h"

Stream_buffer * Stream_channel::buffer()
{
    return _buffer;
}

Stream_channel & Stream_channel::buffer(Stream_buffer * buffer)
{
    _buffer = buffer;

    return *this;
}
