#include "stream_channel_input_ansi.h"

namespace stream::channel::input
{

Ansi::Ansi(Pointer & pointer) 
:
clear(pointer), 
cursor(pointer), 
margins(pointer), 
scroll(pointer), 
font(pointer),
color(pointer),
special(pointer)
{

}

Ansi::~Ansi()
{

}

}; /* namespace: stream::channel::input */
