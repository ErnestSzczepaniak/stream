#include "stream_stack_channel.h"

namespace stream::stack
{

Channel::Channel(char * start, char * stop)
: 
pointer(start, stop)
{

}

Channel::~Channel()
{

}

}; /* namespace: stream::stack */
