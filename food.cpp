#include "food.h"
#include "coordinates.h"
#include "frame.h"

Coordinates Food::get_coordinates() const{
    return *coordinates;
}

void Food::set_coordinates(Coordinates& coord){
    coordinates = &coord;
}

bool Food::nitrogen(){
    return false;
}

int Food::len(){
    return 0;
}

Frame Food::render(){
    return Frame();
}

Food::Food(Coordinates& coord): coordinates(&coord) 
{ }

void Food::enable(){
    enabled = true;
    GOBJEnable();
}
void Food::disable(){
    enabled = false;
    GOBJDisable();
}
bool Food::isEnable(){
    return enabled;
}