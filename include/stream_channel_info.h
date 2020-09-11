#ifndef _stream_channel_info_h
#define _stream_channel_info_h

/**
 * @file	stream_channel_info.h
 * @author	en2
 * @date	11-09-2020
 * @brief	
 * @details	
**/

#include "stream_channel_info_compare.h"

namespace stream::channel
{

class Info
{
public:
    Info(char * buffer, int size);
    ~Info();

    info::Compare compare;

protected:
    

private:
    

}; /* class: Info */


}; /* namespace: stream::channel */


#endif /* define: stream_channel_info_h */