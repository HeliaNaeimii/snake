#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include<vector>
using namespace std;

class Snake
{
protected:
	int speed;
	int nitrogen_time;
	Coordinates direction;
	Coordinates coordinates;
	vector <snake_body> body;
public:
	int Get_Speed();
	void Nitrogen();
	void Move();
};

#endif