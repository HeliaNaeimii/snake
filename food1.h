#ifndef FOOD1_H
#define FOOD1_H

#include "coordinates.h"
#include "food.h"
class Food1:public Food{
    public:
    int len() override;
    bool nitrogen() override;
    Frame render() override;
    Food1(Coordinates& coord);
};

#endif