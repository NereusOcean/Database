#ifndef FieldH
#define FieldH

#include <iostream>
#include <fstream>
#include "Cell.h"
 
class Field{
	private:
	int x, y;
	Cell** field;                                   //Поле разбитое на клетки
	
	Field();
	Field(Field&& other); 				//Конструктор перемещения
	Field (const Field& other);			//Конструктор копирования
	Field & operator = (const Field& other);	//Оператор присваивания
	Field & operator = (Field && other);		//Оператор перемещения
	Field(int x, int y);				//Создание поля
	
				
	
	public:
	
	static Field* GetInstanceOfField(const int x,const int y);	 //Синголтон, через этот метод будем объявлять поля
	Cell** getField();
	~Field();	//Деструктор
	int getX();
	int getY();
	protected:
	static Field* sing;
};



#endif
