// List.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "DoubleLinkedList.h"


int main()
{
	List head;
	head.AddTail(2);
	head.AddTail(4);
	head.AddTail(7);
	head.AddTail(69);
	head.AddTail(57);
	cout << head.Get(2) << "+++\n";
	//head.Del(4);
	//head.Print();
	//head.AddByIndex(4, 147);
	//cout<<head.GetCount()<<"+++\n";
	//head.Print();
	system("pause");
	return 0;
}

