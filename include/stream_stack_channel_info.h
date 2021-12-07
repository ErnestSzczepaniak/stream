#ifndef _stream_stack_channel_info_h
#define _stream_stack_channel_info_h

/**
 * @file	stream_stack_channel_info.h
 * @author	en2
 * @date	25-09-2020
 * @brief	
 * @details	
**/

#include "stream_stack_channel.h"

namespace stream::stack::channel
{

class Info
{
public:
    Info(char * start, char * stop);
    ~Info();

    int offset(char * delimiters);
    int count(char * word, const char * delimiters = " ");
    int words(const char * delimiters = " ");
    int lines();

    Pointer pointer;

protected:
    

private:
    

}; /* class: Info */

}; /* namespace: stream::stack::channel */

#endif /* define: stream_stack_channel_info_h */