#include "stream_channel.h"

namespace stream
{

Channel::Channel(char * buffer, int size) : pointer(buffer, size), _buffer(buffer), _size(size)
{

}

Channel::~Channel()
{

}

int Channel::offset_home()
{
    return pointer.position();
}

int Channel::offset_end()
{
    return tools::string::get::size(pointer);
}

bool Channel::is_aligned()
{
    return (*pointer == 0);
}

Channel & Channel::align_home()
{
    pointer.reset();

    return *this;
}

Channel & Channel::align_end()
{
    pointer += offset_end();

    return *this;
}

}; /* namespace: stream */
