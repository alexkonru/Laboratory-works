#pragma once
#include <iostream>
#include "node.h"
using namespace std;

template <class T>
class LinkedList {
public:
    LinkedList(int s);
    LinkedList(int s, T k);
    LinkedList(const LinkedList<T>& a);
    ~LinkedList();
    void clear();
    void push_front(T data);
    void push_back(T data);
    void pop_front();
    void pop_back();
    Node<T>* getAt(int index);
    void insert(int index, T data);
    void erase(int index);
    LinkedList& operator=(const LinkedList<T>& a);
    int& operator[](int index);
    LinkedList operator+(LinkedList<T>& a);
    LinkedList operator+(const T k);
    friend ostream& operator<<(ostream& out, const LinkedList<T>& a);
    friend istream& operator>>(istream& in, LinkedList<T>& a);
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int size = 0;
};