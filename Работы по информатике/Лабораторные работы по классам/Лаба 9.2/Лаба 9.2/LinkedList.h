#pragma once
#include <iostream>
using namespace std;
const int max_size = 30;

struct Node
{
	int data;
	Node* next, * prev;
};

class LinkedList
{
	Node* head = nullptr;
	Node* tail = nullptr;
	int size;
public:
	LinkedList();
	LinkedList(int s);
	LinkedList(int s, int* mas);
	LinkedList(const LinkedList& l);
	~LinkedList();
	void clear();
	void push_front(int data);
	void push_back(int data);
	void pop_front();
	void pop_back();
	Node* getAt(int index);
	void insert(int index, int data);
	void erase(int index);
	const LinkedList& operator=(const LinkedList& l);
	int operator[] (int i);
	LinkedList operator+(int a);
	LinkedList operator+(LinkedList& l);
	friend ostream& operator<<(ostream& out, const LinkedList& l);
	friend istream& operator>>(istream& in, LinkedList& l);
};

