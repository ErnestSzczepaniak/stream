// #include "stream_channel_set.h"

// namespace stream::channel
// {

// Set::Set(char * start, char * stop) : pointer(start, stop), ansi(pointer)
// {

// }

// Set::~Set()
// {

// }

// Set & Set::character(char value, const char * delimiters)
// {
//     pointer.input("%c%s", value, delimiters);

//     return *this;
// }

// Set & Set::word(char * value, const char * delimiters)
// {
//     auto size = tools::string::get::size(value, delimiters);

//     pointer.input("%.*s", size, value);

//     return *this;
// }

// Set & Set::text(char * value, const char * delimiters)
// {
//     auto size = tools::string::get::size(value, delimiters);

//     pointer.input("%.*s", size, value);

//     return *this;
// }

// }; /* namespace: stream::channel::action */
