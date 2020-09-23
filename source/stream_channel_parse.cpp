#include "stream_channel_parse.h"

namespace stream::channel
{

Parse::Parse(char * start, char * stop) : pointer(start, stop)
{

}

Parse::~Parse()
{

}

bool Parse::is_present(char * option)
{
    return (tools::string::find::substring(pointer.current(), option, pointer.stop() - pointer.current()) != nullptr);
}

}; /* namespace: stream::channel */
