#include "stream_channel.h"

namespace stream
{

Channel::Channel() : input(_buffer, size_buffer), output(_buffer, size_buffer)
{

}

Channel::~Channel()
{

}

}; /* namespace: stream */


