#include "stream_stack_channel_push_ansi_clear.h"

namespace stream::stack::channel::push::ansi
{

Clear::Clear(Pointer & pointer) : display(pointer), line(pointer)
{

}

Clear::~Clear()
{

}

}; /* namespace: stream::stack::channel::push::ansi */
