#ifndef _stream_stack_channel_h
#define _stream_stack_channel_h

/**
 * @file	stream_stack_channel.h
 * @author	en2
 * @date	23-09-2020
 * @brief	
 * @details	
**/

#include "stream_stack_channel_pointer.h"

namespace stream::stack
{

class Channel
{
public:
    Channel(channel::Pointer & pointer);
    ~Channel();

protected:
    template<typename ...Args> void _input_format(const char * format, Args ... args);
    void _input_data(void * data, int size);

    char * _output_format(const char * delimiters = " ");
    void * _output_data(int size);

    char * _find_format(char * string);

private:
    channel::Pointer & _pointer;

}; /* class: Channel */

template<typename ...Args>
void Channel::_input_format(const char * format, Args ... args)
{
    int size;

    if (*_pointer == 0) size = tools::string::insert::append::format(_pointer, _pointer.stop() - _pointer, format, args...);
    else size = tools::string::insert::preppend::format(_pointer, _pointer.stop() - _pointer, format, args...);

    _pointer.move(size);
}

}; /* namespace: stream::stack */

#endif /* define: stream_stack_channel_h */