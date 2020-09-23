#include "stream_stack.h"
#include "tools_string.h"

namespace stream
{

Stack::Stack()
: 
//set(buffer, &buffer[size_buffer]),
pop(buffer, &buffer[size_buffer])
//parse(buffer, &buffer[size_buffer])
{

}

Stack::~Stack()
{

}

int Stack::size()
{
    return strlen(buffer);
}

bool Stack::is_empty()
{
    return (buffer[0] == 0);
}

bool Stack::is_full()
{
    return (buffer[size_buffer - 1] != 0);
}

Stack & Stack::reset()
{
    //get.pointer.reset();
    //set.pointer.reset();

    //memset(buffer, 0, size_buffer);

    return *this;
}

Stack & Stack::operator=(Stack & other)
{
    //set.pointer = other.set.pointer;
    //get.pointer = other.get.pointer;

    //memcpy(buffer, other.buffer, size_buffer);

    return *this;
}

}; /* namespace: stream */
