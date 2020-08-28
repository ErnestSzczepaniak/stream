#ifndef _stream_output_h
#define _stream_output_h

/**
 * @file	stream_output.h
 * @author	en2
 * @date	17-08-2020
 * @brief	
 * @details	
**/

#include "stream_channel.h"

class Stream_channel_output : public Stream_channel
{
public:
    int integer(int word);
    const char * text(int word);


protected:
    void _point_word(int word);

private:
    

}; /* class: Stream_output */


#endif /* define: stream_output_h */