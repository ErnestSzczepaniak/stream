#include "stream_channel.h"
#include "tools_string.h"

namespace stream
{

Channel::Channel()
: 
set(buffer, &buffer[size_buffer]),
get(buffer, &buffer[size_buffer]), 
parse(buffer, &buffer[size_buffer])
{

}

Channel::~Channel()
{

}

int Channel::size_max()
{
    return size_buffer;
}

int Channel::size_actual()
{
    return tools::string::get::size(buffer);
}

Channel & Channel::reset()
{
    get.pointer.reset();
    set.pointer.reset();

    memset(buffer, 0, size_buffer);

    return *this;
}

Channel & Channel::operator=(Channel & other)
{
    set.pointer = other.set.pointer;
    get.pointer = other.get.pointer;

    memcpy(buffer, other.buffer, size_buffer);

    return *this;
}

}; /* namespace: stream */
