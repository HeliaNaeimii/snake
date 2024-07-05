#ifndef PIXEL_H
#define PIXEL_H

#include "coordinates.h"
class Pixel {
    public:
    char32_t ch;
    Coordinates coordinates;
    Pixel(char32_t ch, Coordinates cd);
};

#endif