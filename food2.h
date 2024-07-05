#ifndef FOOD2_H
#define FOOD2_H

#include "coordinates.h"
#include "food.h"
class Food2:public Food{
    public:
    int len() override;
    bool nitrogen() override;
    Frame render() override;
    Food2(Coordinates& coord);
};

#endif