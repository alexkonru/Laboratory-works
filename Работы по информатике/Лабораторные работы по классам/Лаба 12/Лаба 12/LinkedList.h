#pragma once
#include <iostream>
#include "Pair.h"
using namespace std;

template<class T>
class Node
{
public:
    T data;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
};

template <class T>
class LinkedList {
public:
    LinkedList() {};
    LinkedList(int s) {
        T n;
        for (int i = 0; i < s; i++) {
            cout << "�������: ";
            cin >> n;
            push_back(n);
        }
    };
    LinkedList(int s, T k) {
        for (int i = 0; i < s; i++) {
            push_back(k);
        }
    };
    LinkedList(const LinkedList<T>& a) {
        Node<T>* ptr = a.head;
        while (ptr != nullptr) {
            push_back(ptr->data);
            ptr = ptr->next;
        }
    };
    ~LinkedList() {
        clear();
    };
    void clear()
    {
        while (head != NULL)
            pop_front();
        size = 0;
    };
    void push_front(T data) {
        Node<T>* ptr = new Node<T>;
        ptr->data = data;
        if (head != NULL)
            head->prev = ptr;
        if (tail == NULL)
            tail = ptr;
        head = ptr;
        size++;
    };
    void push_back(T data) {
        Node<T>* ptr = new Node<T>;
        ptr->data = data;
        if (tail != NULL) {
            tail->next = ptr;
            ptr->prev = tail;
        }
        if (head == NULL)
            head = ptr;
        tail = ptr;
        tail->next = nullptr;
        size++;
    };
    void pop_front() {
        if (head == nullptr) return;
        Node<T>* ptr = head->next;
        if (ptr != nullptr)
            ptr->prev = nullptr;
        else
            tail = nullptr;
        delete head;
        head = ptr;
        size--;
    };
    void pop_back() {
        if (tail == NULL) return;
        Node<T>* ptr = tail->prev;
        if (ptr != NULL)
            ptr->next = NULL;
        else
            head = NULL;
        delete tail;
        tail = ptr;
        size--;
    };
    Node<T>* getAt(int index) {
        Node<T>* ptr = head;
        int n = 0;
        while (n != index) {
            if (ptr == NULL)
                return ptr;
            ptr = ptr->next;
            n++;
        }
        return ptr;
    };
    void insert(int index, T data) {
        Node<T>* right = getAt(index);
        if (right == NULL)
            return push_back(data);
        Node<T>* left = getAt(index - 1);
        if (left == NULL)
            return push_front(data);
        Node<T>* ptr = new Node<T>;
        ptr->data = data;
        ptr->next = right;
        left->next = ptr;
        size++;
    };
    void erase(int index) {
        Node<T>* ptr = getAt(index);
        if (ptr == NULL)
            return;
        if (index == 0) {
            pop_front();
            return;
        }
        if (ptr->next == NULL) {
            pop_back();
            return;
        }
        Node<T>* left = getAt(index - 1);
        Node<T>* right = ptr->next;
        left->next = right;
        delete ptr;
        size--;
    };
    LinkedList& operator=(const LinkedList<T>& a) {
        if (this == &a) {
            return *this;
        }
        (*this).clear();
        Node<T>* cur = a.head;
        while (cur != nullptr) {
            push_back(cur->data);
            cur = cur->next;
        }
        return *this;
    };
    T& operator[](int index) {
        if (index < size and index >= 0) {
            return getAt(index)->data;
        }
        else
            cout << size << "������! ��� �������� � ����� ��������." << endl;
    };
    LinkedList operator+(LinkedList<T>& c) {
        int size_temp = ((size > c.size) ? c.size : size);
        LinkedList<T> temp;
        for (int i = 0; i < size_temp; i++) {
            temp.push_back((*this).getAt(i)->data + c.getAt(i)->data);
        }
        return temp;
    };
    LinkedList operator+(const T k)
    {
        LinkedList<T> temp;
        for (int i = 0; i < size; i++) {

            temp.push_back((*this).getAt(i)->data + k);
        }
        return temp;
    };
    friend ostream& operator<<(ostream& out, const LinkedList<T>& a) {
        out << endl << "������: " << endl;
        Node<T>* cur = a.head;
        while (cur != nullptr) {
            out << endl << "�������: ";
            out << cur->data << " ";
            cur = cur->next;
        }
        out << endl << "����� ������!" << endl;
        return out;
    };
    friend istream& operator>>(istream& in, LinkedList<T>& a) {
        cout << endl << "������: " << endl;
        Node<T>* cur = a.head;
        while (cur != nullptr) {
            in >> cur->data;
            cur = cur->next;
        }
        cout << endl << "����� ������!" << endl;
        return in;
    };
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
public:
    int size = 0;
};