#ifndef CellH
#define CellH

#include <iostream>
enum Object{
	OBJECT_FREE,
	OBJECT_WALL,
	OBJECT_EXIT,
	OBJECT_ENTRY,
	OBJECT_ITEM,
};

class Cell {
	public:
	Cell();
	void State(Object typeOfObject);
	Object get_state();
	
	private:
	bool isPassable;
	Object state;
	
};



#endif
