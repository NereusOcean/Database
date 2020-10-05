#include "../h/Field.h"

Field::Field(){}

Field::Field(int x, int y){
	this->y = y;
	this->x = x;
	field = new Cell* [x];
	for(int i =0; i < x; ++i){
		field[i] = new Cell[y];
	}	
	for(int i = 0;i <x;++i){
		for(int j = 0;j <y;++j){
			if(i==0||i==x-1||j==0||j==y-1){
				field[i][j].State(OBJECT_WALL);
			}else field[i][j].State(OBJECT_FREE);
		}
	}
	field[x-1][y/2].State(OBJECT_EXIT);
	field[0][y/2].State(OBJECT_ENTRY);
}


//Конструтор копирования
Field::Field (const Field& other){		
	x = other.x;
	y = other.y;
	this->field = new Cell* [x];
	for(int i =0; i < x; ++i){
		this->field[i] = new Cell[y];
	}
	
	for(int i =0; i < x; ++i){
		for(int j = 0; j <y;++j){
			this->field[i][j].State(other.field[i][j].get_state()); 
		}
	}

}

//Конструктор перемещения
Field::Field(Field&& other){
	x = other.x;
	y = other.y;
	this->field = new Cell* [x];
	for(int i =0; i < x; ++i){
		this->field[i] = new Cell[y];
	}
	
	for(int i =0; i < x; ++i){
		for(int j = 0; j <y;++j){
			this->field[i][j]= other.field[i][j]; 
		}
	} 
	other.~Field();
} 		



//оператор присваивания
Field & Field::operator = (const Field& other){

	if(this->field != nullptr){
		for (int i = 0; i < this->x;++i)
			delete[] field[i];
		delete[] field;
	}
	this->x = other.x;
	this->y = other.y;
	
	this->field = new Cell* [x];
	for(int i =0; i < x; ++i){
		this->field[i] = new Cell[y];
	}

	for(int i =0; i < x; ++i){
		for(int j = 0; j <y;++j){
			this->field[i][j].State(other.field[i][j].get_state()); 
		}
	}
	return *this;

}




//Оператор перемещения
Field & Field::operator = (Field && other){
	if(&other == this)
        	return *this;
    for (int i = 0; i < x; i++){
        delete [] this->field[i];
    }
    delete [] this->field;
	this->x = other.x;
	this->y = other.y;
	
	this->field = new Cell* [x];
	for(int i =0; i < x; ++i){
		this->field[i] = new Cell[y];
	}

	for(int i =0; i < x; ++i){
		for(int j = 0; j <y;++j){
			this->field[i][j] = other.field[i][j]; 
		}
	}
	return *this;
}	



Field* Field::sing = nullptr;

Field* Field::GetInstanceOfField(const int x, const int y){
	if(sing==nullptr){
     	   sing = new Field(x,y);
    	}
   	return sing;
}

int Field::getX(){
	return x;
}

int Field::getY(){
	return y;
}

Cell** Field::getField(){
	return field;
}

Field::~Field(){
	for (int i=0;i<this->x;++i){
		delete [] this->field[i];
	}
	delete [] this->field;
}







