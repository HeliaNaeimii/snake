#include "food0.h"
#include "coordinates.h"
#include "frame.h"
#include "pixel.h"

int Food0::len(){
    return 1;
}

bool Food0::nitrogen(){
    return true;
}

Frame Food0::render(){
    Frame frame;
    frame.push_back(
        Pixel('@' ,get_coordinates())
    );
    return frame ;
}

Food0::Food0(Coordinates& coord):
Food(coord)
{}