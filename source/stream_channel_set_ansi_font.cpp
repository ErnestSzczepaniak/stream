// #include "stream_channel_set_ansi_font.h"

// namespace stream::channel::set::ansi
// {

// Font::Font(Pointer & pointer) : _pointer(pointer)
// {
    
// }

// Font::~Font()
// {
    
// }

// Font & Font::bold(bool value)
// {
//     if (value) _pointer.input("%s", "\e[1m");
//     else _pointer.input("%s", "\e[21m");

//     return *this;
// }

// Font & Font::faint(bool value)
// {
//     if (value) _pointer.input("%s", "\e[2m");
//     else _pointer.input("%s", "\e[22m");

//     return *this;
// }

// Font & Font::italic(bool value)
// {
//     if (value) _pointer.input("%s", "\e[3m");
//     else _pointer.input("%s", "\e[23m");

//     return *this;
// }

// Font & Font::underline(bool value)
// {
//     if (value) _pointer.input("%s", "\e[4m");
//     else _pointer.input("%s", "\e[24m");

//     return *this;
// }

// Font & Font::blink(bool value)
// {
//     if (value) _pointer.input("%s", "\e[5m");
//     else _pointer.input("%s", "\e[25m");

//     return *this;
// }

// Font & Font::reverse(bool value)
// {
//     if (value) _pointer.input("%s", "\e[7m");
//     else _pointer.input("%s", "\e[27m");

//     return *this;
// }

// Font & Font::invisible(bool value)
// {
//     if (value) _pointer.input("%s", "\e[8m");
//     else _pointer.input("%s", "\e[28m");

//     return *this;
// }

// Font & Font::crossed(bool value)
// {
//     if (value) _pointer.input("%s", "\e[9m");
//     else _pointer.input("%s", "\e[29m");

//     return *this;
// }

// Font & Font::reset()
// {
//     _pointer.input("%s", "\e[m");

//     return *this;
// }

// }; /* namespace: stream::channel::set::ansi */
