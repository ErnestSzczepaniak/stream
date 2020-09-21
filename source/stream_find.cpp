#include "stream_find.h"

namespace stream
{

Find::Find(char * buffer, int size) : Channel(buffer, size)
{

}

Find::~Find()
{

}

char * Find::word(char * word, const char * delimiters)
{
    auto position = tools::string::find::position::word(pointer, word, delimiters);

    if (position < 0) return nullptr;

    pointer.position(position);

    return pointer;
}

int Find::count(char * word, const char * delimiters)
{
    return tools::string::count::word(pointer, word, delimiters);
}

}; /* namespace: stream */
