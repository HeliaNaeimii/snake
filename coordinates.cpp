#include "coordinates.h"

Coordinates::Coordinates(int x, int y){
	this->x = x;
	this->y = y;
}

Coordinates Coordinates::operator+(Coordinates& other){
	Coordinates New(this->x + other.x, this->y + other.y);
	return New;
}