#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinates
{
public:
	int x, y;
	Coordinates(int x, int y);
	Coordinates operator+ (Coordinates other);
};

#endif