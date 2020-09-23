// #include "stream_channel_set_ansi_margins.h"

// namespace stream::channel::set::ansi
// {

// Margins::Margins(Pointer & pointer) : _pointer(pointer)
// {

// }

// Margins::~Margins()
// {

// }

// Margins & Margins::horizontal(int from, int to)
// {
//     _pointer.input("\e[%d;%dr", from + 1, to + 1);

//     return *this;
// }

// Margins & Margins::vertical(int from, int to)
// {
//     _pointer.input("\e[?69h\e[%d;%ds", from + 1, to + 1);

//     return *this;
// }

// }; /* namespace: stream::channel::set::ansi */
