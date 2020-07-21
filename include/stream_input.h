#ifndef _stream_input_h
#define _stream_input_h

/**
 * @file	stream_input.h
 * @author	en2
 * @date	21-07-2020
 * @brief	
 * @details	
**/

#include "stream_generic.h"

class Stream_input : public Stream_generic
{
public:
    Stream_input(char * buffer_front, char * buffer_back, int size);
 
    template<typename ...P>
    Stream_input & custom(const char * format, P ... params);

    template<typename T> Stream_input & decimal(T value);

    Stream_input & text(const char * text);
    Stream_input & r();
    Stream_input & n();

protected:
    

private:
    

}; /* class: Stream_input */

template<typename ...P>
Stream_input & Stream_input::custom(const char * format, P ... params)
{

}


#endif /* define: stream_input_h */