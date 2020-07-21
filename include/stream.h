#ifndef _stream_h
#define _stream_h

/**
 * @file	stream.h
 * @author	en2
 * @date	21-07-2020
 * @brief	
 * @details	
**/

#include "stream_input.h"

class Stream
{
    static constexpr auto size_buffer = 1024;

public:
    Stream();

    Stream & clear();


    Stream_input input;


protected:
    

private:
    char _buffer_front[size_buffer];
    char _buffer_back[size_buffer];

}; /* class: Stream */

#endif /* define: stream_h */