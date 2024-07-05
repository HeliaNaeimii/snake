#ifndef FRAME_H
#define FRAME_H

#include "pixel.h"
#include <vector>
class Frame: public std::vector<Pixel> {
    public:
    void insert(Frame inp);
    void insert(Pixel inp);
};

#endif