#ifndef _stream_find_h
#define _stream_find_h

/**
 * @file	stream_find.h
 * @author	en2
 * @date	21-09-2020
 * @brief	
 * @details	
**/

#include "stream_channel.h"

namespace stream
{

class Find : public Channel
{
public:
    Find(char * buffer, int size);
    ~Find();

    char * word(char * word, const char * delimiters = " ");
    int count(char * word, const char * delimiters = " ");

}; /* class: Find */

}; /* namespace: stream */

#endif /* define: stream_find_h */