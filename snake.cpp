#include "snake.h"
#include "ascii.h"
#include "coordinates.h"
#include "direction.h"
#include "frame.h"
#include "pixel.h"
#include "snake_block.h"
#include "now.h"
#include <string>
#include <vector>

int Snake::Get_Speed() {
	int effective_speed = speed;
	if (Now() - nitrogen_time > 10000) {
		effective_speed -= 200;

	}
	return effective_speed;
}

void Snake::Nitrogen() {

	nitrogen_time = Now();

}

Snake::Snake(Coordinates coord, int num):
direction(*(new Coordinates(1,0))), 
coordinates(coord),
alive(true),
allowRotate(true),
speed(400)
{
	body = new std::vector<snake_body*>();
	for(int i=0; i<num; i++){
		body->push_back(
			new snake_body(coord)
		);
	}
}

void Snake::run() {
	Move();
	set_delay(
		Get_Speed()
	);
}


void Snake::Move() {
	allowRotate = true;
	for (int i = body->size() - 1; i > 0; i--) {
		snake_body* thisBody = get_body()[i];
		snake_body* nextBody = get_body()[i - 1];
		if (thisBody->initialized)
			thisBody->set_coordinates(
				nextBody->get_coordinates()
			);
		else
			if (nextBody->get_coordinates() != thisBody->get_coordinates())
			{
				thisBody->initialized = true;
			}
	}
	snake_body* Head = get_body()[0];
	Head->set_coordinates(
		Head->get_coordinates() + direction
	);
	Head->get_coordinates().fit(
		get_setting().size
	);
}

Frame Snake::render() {
	Frame* frame = new Frame();
	auto head = get_body()[0];
	char32_t* chptr;
	if(direction==right){
		chptr=&HR;
	}else if(direction==left){
		chptr=&HL;
	}else if(direction==up){
		chptr=&HU;
	}else{
		chptr=&HD;
	}
	frame->insert(
		Pixel(*chptr,head->get_coordinates())
	);
	for(auto sb = body->begin()+1; sb < body->end()-1; sb++){
		if(!(*sb)->initialized) continue;
		auto next = *(sb+1);
		auto previous = *(sb-1);
		auto previousMove = previous->get_coordinates()-(*sb)->get_coordinates();
		auto nextMove = next->get_coordinates()-(*sb)->get_coordinates();
		if(previousMove==up){
			if(nextMove==left){
				chptr = &LUL;
			}else if(nextMove==right){
				chptr = &LDR;
			}else if (nextMove==down) {
				chptr = &V;
			}
		}else if(previousMove==left){
			if(nextMove==up){
				chptr = &LUL;
			}else if(nextMove==right){
				chptr = &H;
			}else if (nextMove==down) {
				chptr = &LDL;
			}
		}else if(previousMove==down){
			if(nextMove==left){
				chptr = &LDL;
			}else if(nextMove==right){
				chptr = &LUR;
			}else if (nextMove==up) {
				chptr = &V;
			}
		}else if(previousMove==right){
			if(nextMove==left){
				chptr = &H;
			}else if(nextMove==up){
				chptr = &LDR;
			}else if (nextMove==down) {
				chptr = &LUR;
			}
		}
		frame->insert(
			Pixel(*chptr, (*sb)->get_coordinates())
		);
	}
	auto end = body->end();
	if ((*(end-1))->initialized){
		if (((*(end-1))->get_coordinates().x==(*(end-2))->get_coordinates().x)){
			chptr = &V;
		}else{
			chptr = &H;
		}
		frame->insert(
			Pixel(*chptr, (*(end-1))->get_coordinates())
		);
	}
	return *frame;
}

void Snake::TurnLeft(){
	if(allowRotate){
		direction = Coordinates(direction.y,-direction.x);
		allowRotate = false;
	}
}

void Snake::TurnRight(){
	if(allowRotate){
		direction = Coordinates(-direction.y,direction.x);
		allowRotate = false;
	}
}

snake_body* Snake::get_head(){
	return get_body()[0];
}

void Snake::Feed(int num){
	for(int i = 0; i<num; i++){
		body->push_back(
			new snake_body((*(body->end()-1))->get_coordinates())
		);
	}
}

std::vector<snake_body*> Snake::get_body(){
	return *body;
}

int Snake::len(){
	return body->size();
}

void Snake::die(){
	alive = false;
	GOBJDisable();
}

bool Snake::isAlive(){
	return alive;
}

std::string Snake::log(){
	return "snake";
}