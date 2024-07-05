#ifndef SNAKE_BLOCK_H
#define SNAKE_BLOCK_H
#include "coordinates.h"

class snake_body {
	private:
	Coordinates* coordinates;
	public:
	snake_body(Coordinates& coord);
	snake_body(Coordinates* coord);
	bool initialized;
	Coordinates& get_coordinates();
	void set_coordinates(Coordinates& coordinates);
};
#endif