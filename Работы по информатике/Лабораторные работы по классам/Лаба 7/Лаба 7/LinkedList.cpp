#include "LinkedList.h"
#include "node.h"
#include <iostream>
using namespace std;
template<class T>
LinkedList<T>::LinkedList<T>(int s) {
    int n;
    for (int i = 0; i < s; i++) {
        cout << "Элемент: ";
        cin >> n;
        push_back(n);
    }
}
template <class T>
LinkedList<T>::LinkedList<T>(int s, T k) {
    for (int i = 0; i < s; i++) {
        cout << "Элемент: ";
        push_back(k);
    }
}
template <class T>
LinkedList<T>::LinkedList<T>(const LinkedList<T>& a) {
    Node<T>* ptr = a.head;
    while (ptr != nullptr) {
        push_back(ptr->data);
        ptr = ptr->next;
    }
}
template <class T>
LinkedList<T>::~LinkedList<T>() {
    clear();
}
template <class T>
void LinkedList<T>::clear() {
    while (head != NULL)
        pop_front();
    size = 0;
}
template <class T>
void LinkedList<T>::push_front(T data) {
    Node<T>* ptr = new Node<T>;
    ptr->data = data;
    if (head != NULL)
        head->prev = ptr;
    if (tail == NULL)
        tail = ptr;
    head = ptr;
    size++;
}
template <class T>
void LinkedList<T>::push_back(T data) {
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
}
template <class T>
void LinkedList<T>::pop_front() {
    if (head == nullptr) return;
    Node<T>* ptr = head->next;
    if (ptr != nullptr)
        ptr->prev = nullptr;
    else
        tail = nullptr;
    delete head;
    head = ptr;
    size--;
}
template <class T>
void LinkedList<T>::pop_back() {
    if (tail == NULL) return;
    Node<T>* ptr = tail->prev;
    if (ptr != NULL)
        ptr->next = NULL;
    else
        head = NULL;
    delete tail;
    tail = ptr;
    size--;
}
template <class T>
Node<T>* LinkedList<T>::getAt(int index) {
    Node<T>* ptr = head;
    int n = 0;
    while (n != index) {
        if (ptr == NULL)
            return ptr;
        ptr = ptr->next;
        n++;
    }
    return ptr;
}
template <class T>
void LinkedList<T>::insert(int index, T data) {
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
}
template <class T>
void LinkedList<T>::erase(int index) {
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
}
template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& a) {
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
}
template <class T>
int& LinkedList<T>::operator[](int index) {
    if (index < size and index >= 0) {
        return getAt(index)->data;
    }
    else
        cout << size << "Ошибка! Нет элемента с таким индексом." << endl;
}
template <class T>
LinkedList<T> LinkedList<T>::operator+(LinkedList& c) {
    int size_temp = ((size > c.size) ? c.size : size);
    LinkedList<T> temp;
    for (int i = 0; i < size_temp; i++){
        temp.push_back ((*this)[i] + c[i]);
    }
    return temp;
}
template <class T>
LinkedList<T> LinkedList<T>::operator+(const T k) {
    LinkedList<T> temp;
    for (int i = 0; i < size; i++) {
        temp.push_back((*this)[i] + k);
    }
    return temp;
}
template <class T>
ostream& operator<<(ostream& out, const LinkedList<T>& a) {
    out << endl << "Список: " << endl;
    Node<T>* cur = a.head;
    while (cur != nullptr) {
        out << endl << "Элемент: ";
        out << cur->data << " ";
        cur = cur->next;
    }
    out << endl << "Конец списка!" << endl;
    return out;
}
template <class T>
istream& operator>>(istream& in, LinkedList<T>& a) {
    cout << endl << "Список: " << endl;
    Node<T>* cur = a.head;
    while (cur != nullptr) {
        in >> cur->data;
        cur = cur->next;
    }
    cout << endl << "Конец списка!" << endl;
    return in;
}