#include "stream_channel.h"

namespace stream
{

Channel::Channel() : input(_buffer, size_buffer), output(_buffer, size_buffer)
{
    
}

Channel::~Channel()
{

}

Channel & Channel::reset()
{
    memset(_buffer, 0, size_buffer);

    input.pointer.move_start();
    output.pointer.move_start();
}

}; /* namespace: stream */


