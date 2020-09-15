#include "stream_channel.h"

namespace stream
{

Channel::Channel(char * buffer, int size) : pointer(buffer, size), _buffer(buffer), _size(size)
{

}

Channel::~Channel()
{

}

int Channel::offset_left()
{
    return pointer.position();
}

int Channel::offset_right()
{
    return tools::string::get::size(pointer);
}

bool Channel::is_aligned()
{
    return (*pointer == 0);
}

Channel & Channel::align_left()
{
    pointer.reset();

    return *this;
}

Channel & Channel::align_right()
{
    pointer += offset_right();

    return *this;
}

}; /* namespace: stream */
