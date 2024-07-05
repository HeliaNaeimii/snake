#include "food1.h"
#include "coordinates.h"
#include "frame.h"
#include "pixel.h"

int Food1::len(){
    return 3;
}

bool Food1::nitrogen(){
    return false;
}

Frame Food1::render(){
    Frame frame;
    frame.push_back(
        Pixel('0' ,get_coordinates())
    );
    return frame ;
}

Food1::Food1(Coordinates& coord):
Food(coord)
{}