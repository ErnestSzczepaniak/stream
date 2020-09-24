#include "stream_stack.h"
#include "tools_string.h"

namespace stream
{

Stack::Stack()
: 
push(buffer, &buffer[size_buffer]),
pop(buffer, &buffer[size_buffer]),
parse(buffer, &buffer[size_buffer])
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
    push.pointer.reset();
    pop.pointer.reset();
    parse.pointer.reset();

    memset(buffer, 0, size_buffer);

    return *this;
}

Stack & Stack::operator=(Stack & other)
{
    push.pointer = other.push.pointer;
    pop.pointer = other.pop.pointer;
    parse.pointer = other.parse.pointer;

    memcpy(buffer, other.buffer, size_buffer);

    return *this;
}

}; /* namespace: stream */
