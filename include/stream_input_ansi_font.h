#ifndef _stream_input_ansi_font_h
#define _stream_input_ansi_font_h

/**
 * @file	stream_input_ansi_font.h
 * @author	en2
 * @date	08-09-2020
 * @brief	
 * @details	
**/

#include "stream_pointer.h"

namespace stream::input::ansi
{

class Font
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

private:
    Pointer & _pointer;

}; /* class: Font */

}; /* namespace: stream::input::ansi */

#endif /* define: stream_input_ansi_font_h */