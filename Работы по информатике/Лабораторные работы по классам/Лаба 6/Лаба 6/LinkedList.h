#pragma once
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next, *prev;
};

class Iterator
{
    friend class LinkedList;
public:
    Iterator() { element = 0; }
    Iterator(const Iterator& it) { element = it.element; }
    bool operator==(const Iterator& it) { return element == it.element; }
    bool operator!=(const Iterator& it) { return element != it.element; };
    Iterator& operator++() { element = element->next; return *this; };
    Iterator& operator--() { element = element->prev; return *this; }
    int& operator *() const { return element->data; }
public:
    Node* element;
};

class LinkedList {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
public:
    LinkedList();
    LinkedList(int s);
    LinkedList(const LinkedList& a);
    ~LinkedList();
    void clear();
    void push_front(int data);
    void push_back(int data);
    void pop_front();
    void pop_back();
    Node* getAt(int index);
    void insert(int index, int data);
    void erase(int index);
    LinkedList& operator=(const LinkedList& a);
    int& operator[](int index);
    LinkedList operator+(LinkedList& a);
    LinkedList operator+(int k);
    friend ostream& operator<<(ostream& out, const LinkedList& a);
    friend istream& operator>>(istream& in, LinkedList& a);
    Iterator first() { return beg; }
    Iterator last() { return end; }
private:
    int* data;
    Iterator beg;
    Iterator end;
};