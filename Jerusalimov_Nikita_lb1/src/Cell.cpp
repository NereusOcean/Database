#include "../h/Cell.h" 

Cell::Cell() {}

void Cell::State(Object typeOfObject){
	this->state = typeOfObject;
	if(typeOfObject == OBJECT_WALL) this->isPassable = 0;

}

Object Cell::get_state() {return this->state;}
