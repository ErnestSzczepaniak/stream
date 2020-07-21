#include "stream_generic.h"

Stream_generic::Stream_generic(char * buffer_front, char * buffer_back, int size) 
: 
_buffer_front(buffer_front),
_pointer_front(buffer_front), 
_buffer_back(buffer_back), 
_pointer_back(buffer_back), 
_size(size)
{
    
}

Stream_generic & Stream_generic::reset()
{
    _pointer_front = _buffer_front;
    _pointer_back = _buffer_back;

    return *this;
}