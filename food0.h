#ifndef FOOD0_H
#define FOOD0_H

#include "coordinates.h"
#include "food.h"
class Food0: public Food{
    public:
    int len() override;
    bool nitrogen() override;
    Frame render() override;
    Food0(Coordinates& coord);
};

#endif