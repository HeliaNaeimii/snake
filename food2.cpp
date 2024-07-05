#include "food2.h"
#include "coordinates.h"
#include "frame.h"
#include "pixel.h"

int Food2::len(){
    return 1;
}

bool Food2::nitrogen(){
    return false;
}

Frame Food2::render(){
    Frame frame;
    frame.push_back(
        Pixel('$' ,get_coordinates())
    );
    return frame ;
}

Food2::Food2(Coordinates& coord):
Food(coord)
{}