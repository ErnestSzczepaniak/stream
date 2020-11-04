#ifndef _stream_stack_channel_parse_h
#define _stream_stack_channel_parse_h

/**
 * @file	stream_stack_channel_parse.h
 * @author	en2
 * @date	23-09-2020
 * @brief	
 * @details	
**/

#include "stream_stack_channel.h"

namespace stream::stack::channel
{

class Parse : public Channel
{
public:
    Parse(char * start, char * stop);
    ~Parse();

    bool is_present(const char * delimiters = " ");
    bool is_equal(char * value, const char * delimiters = " \0");

    unsigned int decimal(const char * delimiters = " ");
    unsigned int hexadecimal(const char * delimiters = " "); 
    float floating(const char * delimiters = " ");
    char character(const char * delimiters = " ");

    char * word(const char * delimiters = " ");
    char * text(const char * delimiters = "\0");

    Parse & option(char * option);

    Pointer pointer;

private:
    char * _option;

}; /* class: Parse */

}; /* namespace: stream::channel */

#endif /* define: stream_stack_channel_parse_h */