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
    auto * ptr = pointer_output(pointer, word, delimiters);

    return *ptr;
}

char * Output::word(int word, const char * delimiters)
{
    
}


}; /* namespace: stream::channel */