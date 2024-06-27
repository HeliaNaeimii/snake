#ifndef SNAKE_BLOCK_H
#define SNAKE_BLOCK_H
#include "coordinates.h"

class snake_body {
private:
	Coordinates* coordinates;

public:
	bool initialized;
	Coordinates get_coordinates();
	void set_coordinates(Coordinates& coordinates);
};
#endif