#ifndef RANDOM_H
#define RANDOM_H

#include "coordinates.h"
#include "food.h"
#include "setting.h"
class Random{
    private:
    Setting& setting;
    public:
    Random(Setting& setting);
    int Next(int a, int b);
    Coordinates* randomCoordinates();
    Food* randomFood();
};

#endif