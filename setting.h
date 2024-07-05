#ifndef SETTING_H
#define SETTING_H

#include "coordinates.h"
class Setting {
    public:
    Setting(int x, int y, int enemies);
    Coordinates size;
    int enemies;
};

#endif