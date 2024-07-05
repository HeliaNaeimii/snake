#ifndef FOOD_H
#define FOOD_H

#include "coordinates.h"
#include "g_obj.h"
#include "snake.h"
class Food:public GObj {
    private:
    void OhMyGodEat(Snake& snake);
    bool enabled=true;

    protected:
    Coordinates* coordinates;

    public:
    void disable();
    void enable();
    bool isEnable();
    Food(Coordinates& coord);
    Coordinates get_coordinates() const;
    void set_coordinates(Coordinates& coord);
    virtual bool nitrogen();
    virtual int len();
    Frame render() override;
};

#endif