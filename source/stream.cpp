#include "stream.h"

Stream::Stream() : input(_buffer_front, _buffer_back, size_buffer)
{
    
}