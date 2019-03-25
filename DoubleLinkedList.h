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
		head = tail = NULL;
		
		count = 0;
	}

	int GetCount() { return count; }//O(1)

	// ���������� � ����� ������
	void AddTail(int n) {//O(1)
		Node *temp = new Node;
		temp->next = 0;
		temp->num = n;
		temp->prev = tail;

		if (tail != 0)tail->next = temp;
		if (count == 0)head = tail = temp;
		else tail = temp;

		count++;
	}

	// ���������� � ������ ������
	void AddHead(int n) {//O(1)
		Node *temp = new Node;
		temp->prev = 0;
		temp->num = n;
		temp->next = head;

		if (head != 0)head->prev = temp;
		if (count == 0)head = tail = temp;
		else head = temp;

		count++;
	}

	void AddByIndex(int pos,int num) {
		Node *temp = new Node;

		if (pos == 1) {

			temp->prev = 0;
			temp->next = head;
			temp->num = num;

			if (head != 0)head->prev = temp;
			if (count == 0)head = tail = temp;
			else head = temp;

			count++;
			return;

		} 
		else if (pos == count) {
			temp->next = 0;
			temp->prev = tail;
			temp->num = num;
			if (tail != 0)tail->next = temp;
			if (count == 0)head = tail = temp;
			else tail = temp;

			count++;
			return;
		}
		else {
			Node *newNode = head;
			for (int i = 1; i < pos; ++i) newNode = newNode->next;
			
			Node *newN = new Node;
			newN->next = newNode;
			newN->prev = newNode->prev;
			newN->num = num;
			
			tail = newN;

			count++;
		}
	}

	void Del(int pos) {//O(n)
		if (pos == 0) return;
		if (pos<0 || pos>count) {
			std::cout << "incorect position!\n";
			return;
		}

		
		Node *del = head;

		for (int i = 1; i < pos; ++i) del = del->next;

		Node *prevDel = del->prev;
		Node *afterDel = del->next;
		//������� �������� �� ������ ���� ��� �� ������ � �� �����, ���� ��� �������� �������.
		if (prevDel != 0 && count != 1) prevDel->next = afterDel;//���� ������� �� ������
		if (afterDel != 0 && count != 1)afterDel->prev = prevDel; //���� ������� �� �����
	}
	//����� �� �����
	bool Contains(int soughtFor) {
		Node *temp = head;
		for (; temp != 0; temp = temp->next) {
			if (temp->num == soughtFor) return true;
		}
		return false;
	}
	//����� �� �������
	int Get(int pos) {
		Node *temp = head;
		int i = 1;
		while (i < pos)
		{
			temp = temp->next;
			++i;
		}
		return temp->num;
	}

	// ����� ������
	void Print() { // O(n)
		//��������� ���� �� �������� � ������
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
	
	// ����� ������������� ��������
	void Print(int pos) { // O(n)
		//��������� �� �������
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
/*public void Intersect(link list, link list1, link list2){
	for( i < n){
		for( j < m){
			if(n==m){ //O(n)
				O(1).O(n)
			}
		}
	}


	//O(n * m + n) // ��� �������, ��� ��� 
	or
	//O(n * m + n * n) = O(n * m + n^2) // ����� ����
	or
	//O(n*m + n*m + n)=O(2nm + n)=O(nm + n)//�����

}*/