#include "stream_input.h"

Stream_input::Stream_input(char * buffer_front, char * buffer_back, int size)
:
Stream_generic(buffer_front, buffer_back, size) 
{

}

Stream_input & text(const char * text);
Stream_input & r();
Stream_input & n();