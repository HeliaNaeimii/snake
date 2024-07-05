#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinates{
	public:
	int x, y;
	Coordinates(int x, int y);
	Coordinates& operator+ (Coordinates& other);
	Coordinates& operator- (Coordinates& other);
	bool operator== (Coordinates& other) const;
	bool operator!= (Coordinates& other) const;
	void fit(Coordinates& size);
};

#endif