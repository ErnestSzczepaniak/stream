#include "stream_channel_output.h"
#include "tools_string.h"

namespace stream::channel
{

Output::Output(char * buffer, int size) : pointer(buffer, size)
{

}

Output::~Output()
{

}

char Output::character(int word, const char * delimiters)
{

}

char * Output::word(int word, const char * delimiters)
{

}


}; /* namespace: stream::channel */