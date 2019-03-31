#pragma once
#include "pch.h"
#include <iostream>

struct Node {
	int num;
	Node *next;
	Node *prev;
};
class List {
	Node *head;
	Node *tail;
	
	int count;
public:

	List() {
		head = tail = nullptr;
		
		count = 0;
	}

	int GetCount() { return count; }//O(1)

	// Добавление в конец списка
	void AddTail(int n) {//O(1)
		Node *temp = new Node;
		temp->next = nullptr;
		temp->num = n;
		temp->prev = tail;

		if (tail != nullptr)tail->next = temp;
		if (count == 0)head = tail = temp;
		else tail = temp;
		
		count++;
	}

	// Добавление в начало списка
	void AddHead(int n) {//O(1)
		Node *temp = new Node;
		temp->prev = nullptr;
		temp->num = n;
		temp->next = head;

		if (head != nullptr)head->prev = temp;
		if (count == 0)head = tail = temp;
		else head = temp;

		count++;
	}
	//Добавление по индексу 
	void AddByIndex(int pos,int num) {// O(n) так как это самый худший вариант 
		try
		{
			Node *temp = new Node;
			if (pos < 0 || pos>count+1) {
				throw std::out_of_range{ "Index should be > 0 and <= count. Incorect argument! " };
			}
			if (pos < count / 2) {
				Node *temp = head;
				int i = 0;
				while (i++ < pos)temp = temp->next;
				Node *newNode = new Node;
				newNode->num = num;
				newNode->next = temp;
				newNode->prev = temp->prev;							// O(n+n)=O(2n)=O(n)
				temp->prev = newNode;

				if (pos == 0) AddHead(num);
				else newNode->prev->next = newNode;

				count++;
			}
			else {

				Node *temp = tail;

				int i = count;
				while (--i > pos)temp = temp->prev;

				Node *newNode = new Node;
				if (pos == count) AddTail(num);
				else {
					newNode->next = temp;
					newNode->num = num;
					newNode->prev = temp->prev;
					temp->prev = newNode;
					newNode->prev->next = newNode;
					count++;
				}


			}
		}
		catch (const std::exception&ex)
		{
			std::cerr << "Eror 102 " << ex.what();
		}
		
	}

	//Пересечение 2 списков
	List Intersect(List list, List list2) {
			List headResult;
			Node *temp = list.head;

			for (; temp != nullptr; temp = temp->next) {
				if (list2.Contains(temp->num)) headResult.AddTail(temp->num);
			}
			return headResult;
	}


	void Del(int pos) {//O(n)
		try
		{
			if (pos<0 || pos>count - 1) {
				throw std::out_of_range{ "Index should be > 0 and <= count. Incorect argument! " };
			}

			if (pos == 0) {
				Node *del = head;
				del->next->prev = nullptr;
				head = del->next;
			}
			else {
				Node *del = head;

				for (int i = 0; i < pos; ++i) del = del->next;

				Node *prevDel = del->prev;
				Node *afterDel = del->next;
				//Удаляем эллемент из списка если это не голова и не хвост, даем ему значение соседей.
				if (prevDel != 0 && count != 1) prevDel->next = afterDel;//Если удаляем не голову
				if (afterDel != 0 && count != 1)afterDel->prev = prevDel; //Если удаляем не хвост
				count--;
			}
		}
		catch (const std::exception&ex)
		{
			std::cerr << "Eror 102 " << ex.what();
		}
		
		
	}
	//Поиск по числу
	bool Contains(int soughtFor) {
		Node *temp = head;
		for (; temp != nullptr; temp = temp->next) {
			if (temp->num == soughtFor) return true;
		}
		return false;
	}
	//Поиск по индексу
	int Get(int pos) {
		try
		{
			if (pos<0 || pos>count - 1) {
				throw std::out_of_range{ "Index should be > 0 and <= count. Incorect argument! " };
			}
			Node *temp = head;
			int i = 0;
			while (i < pos && temp != 0)
			{
				temp = temp->next;
				i++;
			}
			if (temp == nullptr)
				return 0;
			else
				return temp->num;
		}
		catch (const std::exception&ex)
		{
			std::cerr << "Eror 102 " << ex.what();
		}
		
	}

	//Поиск числа и вдача его позиции 
	int PosThisNum(int soughtFor) {
		Node *temp = head;
		int pos = 0;
		for (; temp != nullptr; temp = temp->next) {
			
			if (temp->num == soughtFor) return pos;
			pos++;
		}
		return false;
	}
	// Вывод списка
	void Print() { // O(n)
		//Проверяем есть ли элементы в списке
			Node *temp = head;
			std::cout << "( ";
			while (temp->next != nullptr) {
				std::cout << temp->num << ", ";
				temp = temp->next;
			}
			std::cout << temp->num << " )\n";
	}
	
	// Вывод определенного элемента
	void Print(int pos) { // O(n)
		try
		{
			//Допустима ли позиция
			if (pos < 0 || pos>count) {
				throw std::invalid_argument{ "Incorect argument!" };
			}

			Node *temp;

			if (pos <= count / 2) {
				temp = head;
				int i = 1;
				while (i < pos) {
					temp = temp->next;
					i++;
				}
			}
			else {
				temp = tail;

				int i = 1;

				while (i <= count - pos) {
					temp = temp->prev;
					i++;
				}
			}
			std::cout << pos << " element: ";
			std::cout << temp->num << std::endl;
		}
		catch (const std::exception&ex)
		{
			std::cerr << "Eror 104 " << ex.what();
		}
		
	}

	
};
