#include "stream_input_ansi_clear.h"

namespace stream::input::ansi
{

Clear::Clear(Pointer & pointer) : display(pointer), line(pointer)
{

}

Clear::~Clear()
{

}

}; /* namespace: stream::input::ansi */
