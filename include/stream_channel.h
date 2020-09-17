#ifndef _stream_channel_h
#define _stream_channel_h

/**
 * @file	stream_channel.h
 * @author	en2
 * @date	15-09-2020
 * @brief	
 * @details	
**/

#include "stream_pointer.h"

namespace stream
{

class Channel
{
public:
    Channel(char * buffer, int size);
    ~Channel();

    int offset_home();
    int offset_end();

    bool is_aligned();
    Channel & align_home();
    Channel & align_end();

    Pointer pointer;

private:
    char * _buffer;
    int _size;

}; /* class: Channel */


}; /* namespace: stream */


#endif /* define: stream_channel_h */