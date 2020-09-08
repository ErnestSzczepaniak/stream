#include "stream_channel_input_ansi_clear.h"

namespace stream::channel::input::ansi
{

Clear::Clear(Pointer & pointer) : display(pointer), line(pointer)
{

}

Clear::~Clear()
{

}

}; /* namespace: stream::channel::input::ansi */
