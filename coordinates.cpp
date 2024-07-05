#include "coordinates.h"

Coordinates::Coordinates(int x, int y){
	this->x = x;
	this->y = y;
}

Coordinates& Coordinates::operator+(Coordinates& other){
	Coordinates* New = new Coordinates(this->x + other.x, this->y + other.y);
	return *New;
}

Coordinates& Coordinates::operator-(Coordinates& other){
	Coordinates* New = new Coordinates(this->x - other.x, this->y - other.y);
	return *New;
}


bool Coordinates::operator==(Coordinates& other) const {
	if(this==nullptr) return false;
	return x==other.x && y==other.y;
}

bool Coordinates::operator!=(Coordinates& other) const {
	return !(*(this)==other);
}
int mod(int x, int y){
	if(x<y){
		if(x>=0){
			return x;
		}
		return mod(x+y, y);
	}
	return mod(x-y, y);
}

void Coordinates::fit(Coordinates& size) {
	x = mod(x,size.x);
	y = mod(y, size.y);
}