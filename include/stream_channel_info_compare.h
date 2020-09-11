#ifndef _stream_channel_info_compare_h
#define _stream_channel_info_compare_h

/**
 * @file	stream_channel_info_compare.h
 * @author	en2
 * @date	11-09-2020
 * @brief	
 * @details	
**/

namespace stream::channel::info
{

class Compare
{
public:
    Compare(char * buffer, int size);
    ~Compare();

    int difference(char * string, int word = 0, const char * delimiters = " ");
    bool equality(char * string, int word = 0, const char * delimiters = " ");

private:
    char * _buffer;
    int _size;    

}; /* class: Compare */


}; /* namespace: stream::channel::info */


#endif /* define: stream_channel_info_compare_h */