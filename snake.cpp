#include "snake.h"
#include "snake_block.h"

int Snake::Get_Speed() {
	int effective_speed = speed;
	if (Now() - nitrogen_time > 10) {
		effective_speed -= 5;

	}
	return effective_speed;
}

void Snake::Nitrogen() {

	nitrogen_time = Now();

}

void Snake::Move() {
	for (int i = body.size() - 1; i > 0; i--) {
		snake_body& thisBody = body[i];
		snake_body& nextBody = body[i - 1];
		if (thisBody.initialized)
			thisBody.set_coordinates(
				nextBody.get_coordinates()
			);
		else
			if (nextBody.get_coordinates() != thisBody.get_coordinates())
			{
				thisBody.initialized = true;
			}
	}
	snake_body& Head = body[0];
	Head.set_coordinates(
		Head.get_coordinates() + direction
	);
}

