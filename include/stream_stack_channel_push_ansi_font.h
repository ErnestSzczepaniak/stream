#ifndef _stream_stack_channel_push_ansi_font_h
#define _stream_stack_channel_push_ansi_font_h

/**
 * @file	stream_stack_channel_push_ansi_font.h
 * @author	en2
 * @date	22-09-2020
 * @brief	
 * @details	
**/

#include "stream_stack_channel.h"

namespace stream::stack::channel::push::ansi
{

class Font : public Channel
{
public:
    Font(Pointer & pointer);
    ~Font();

    Font & bold(bool value);
    Font & faint(bool value);
    Font & italic(bool value);
    Font & underline(bool value);
    Font & blink(bool value);
    Font & reverse(bool value);
    Font & invisible(bool value);
    Font & crossed(bool value);
    Font & reset();

}; /* class: Font */

}; /* namespace: stream::stack::channel::push::ansi */

#endif /* define: stream_stack_channel_push_ansi_font_h */