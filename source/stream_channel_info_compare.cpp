#include "stream_channel_info_compare.h"
#include "tools_string.h"

namespace stream::channel::info
{

Compare::Compare(char * buffer, int size)
:
_buffer(buffer),
_size(size)
{

}

Compare::~Compare()
{

}

int Compare::difference(char * string, int word, const char * delimiters)
{
    auto * ptr = tools::string::get::word(_buffer, word, delimiters);

    return tools::string::compare::difference(string, ptr, delimiters);
}

bool Compare::equality(char * string, int word, const char * delimiters)
{

}

}; /* namespace: stream::channel::info */
