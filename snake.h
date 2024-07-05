#ifndef SNAKE_H
#define SNAKE_H

#include <string>
#include <vector>
#include "coordinates.h"
#include "frame.h"
#include "g_obj.h"
#include "snake_block.h"
#include "task.h"

class Snake: public Task,public GObj {
	protected:
	int speed;
	long nitrogen_time;
	Coordinates direction;
	Coordinates coordinates;
	std::vector<snake_body*>* body;
	bool alive;
	bool allowRotate;
	public:
	Snake(Coordinates coord, int len);
	int Get_Speed();
	void Nitrogen();
	void Move();
	void TurnLeft();
	void TurnRight();
	void Feed(int num);
	void run() override;
	int len();
	void die();
	bool isAlive();
	std::vector<snake_body*> get_body();
	Frame render() override;
	snake_body* get_head();
	std::string log() override;
};

#endif