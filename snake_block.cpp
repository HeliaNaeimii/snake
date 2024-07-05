#include"snake_block.h"

Coordinates& snake_body::get_coordinates() {
	return *coordinates;
}
void snake_body::set_coordinates(Coordinates& coordinates) {
	this->coordinates = &coordinates;
}
snake_body::snake_body(Coordinates& coord): 
coordinates(new Coordinates(coord)),
initialized(false)
{ }
snake_body::snake_body(Coordinates* coord):
coordinates(new Coordinates(*coord)),
initialized(false)
{ }