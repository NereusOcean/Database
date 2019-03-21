// List.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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
		head = tail = NULL;
		count = 0;
	}
	
	int GetCount() { return count; }
	
	void Del(int pos) {
		if (pos == 0) return;
		if (pos<0 || pos>count) {
			std::cout << "incorect position!\n";
			return;
		}

		int i = 0;
		Node *del = head;

		while (i <= pos) {
			del = del->next;
			i++;
		}

		Node *prevDel = del->prev;
		Node *afterDel = del->next;
		//Удаляем эллемент из списка если это не голова и не хвост, даем ему значение соседей.
		if (prevDel != 0 && count != 1) prevDel->next = afterDel;//Если удаляем не голову
		if (afterDel != 0 && count != 1)afterDel->prev = prevDel; //Если удаляем не хвост
	}
	
	// Добавление в конец списка
	void AddTail(int n) {
		Node *temp = new Node;
		temp->next = 0;
		temp->num = n;
		temp->prev = tail;

		if (tail != 0)tail->next = temp;
		if (count == 0)head = tail = temp;
		else tail = temp;

		count++;
	}

	// Добавление в начало списка
	void AddHead(int n) {
		Node *temp = new Node;
		temp->prev = 0;
		temp->num = n;
		temp->next = head;

		if (head != 0)head->prev = temp;
		if (count == 0)head = tail = temp;
		else head = temp;

		count++;
	}

	// Вывод списка
	void Print() {
		//Проверяем есть ли элементы в списке
		if (count != 0) {
			Node *temp = head;
			std::cout << "( ";
			while (temp->next != 0) {
				std::cout << temp->num << ", ";
				temp = temp->next;
			}
			std::cout << temp->num << " )\n";
		}
	}
	// Вывод определенного элемента
	void Print(int pos) {
		//Допустима ли позиция
		if (pos < 1 || pos>count) {
			std::cout << "incorect position!";
			return;
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
};


int main()
{
	List head;
	head.AddTail(2);
	head.AddTail(4);
	head.AddTail(7);
	head.Del(2);
	head.Print();

	head.AddHead(147);

	head.Print();
	system("pause");
	return 0;
}

