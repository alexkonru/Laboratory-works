#pragma once
#include <iostream>
struct Node
{
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head = nullptr;
    int size = 0;
public:
    LinkedList(int s, int k = 0);
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
    LinkedList operator+();
    friend ostream& operator<<(ostream& out, const LinkedList& a);
    friend istream& operator>>(istream& in, LinkedList& a);
};