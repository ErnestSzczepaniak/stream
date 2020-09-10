#include "stream_generic.h"

Stream_generic & Stream_generic::reset()
{
    for (int i = 0; i < size(); i++) channel(i)->reset();

    return *this;
}