#include "LinkedList.h"
#include <iostream>
using namespace std;
LinkedList::LinkedList() {
    push_back(0);
    beg.element = head;
    end.element = tail->next;
}
LinkedList::LinkedList(int s) {
    int n;
    for (int i = 0; i < s; i++) {
        cout << "Элемент: ";
        cin >> n;
        push_back(n);
    }
    beg.element = head;
    end.element = tail->next;
}
LinkedList::LinkedList(const LinkedList& a) {
    Node* ptr = a.head;
    while (ptr != nullptr) {
        push_back(ptr->data);
        ptr = ptr->next;
    }
    beg = a.beg;
    end = a.end;
}
LinkedList::~LinkedList() {
    clear();
}
void LinkedList::clear() {
    while (head != NULL)
        pop_front();
    size = 0;
}
void LinkedList::push_front(int data) {
    Node* ptr = new Node;
    ptr->data = data;
    ptr->next = head;
    if (head != NULL)
        head->prev = ptr;
    if (tail == NULL)
        tail = ptr;
    head = ptr;
    size++;
    beg.element = head;
}
void LinkedList::push_back(int data) {
    Node* ptr = new Node;
    ptr->data = data;
    ptr->prev = tail;
    if (tail != NULL)
        tail->next = ptr;
    if (head == NULL)
        head = ptr;
    tail = ptr;
    tail->next = nullptr;
    size++;
    end.element = tail->next;
}
void LinkedList::pop_front() {
    if (head == nullptr) return;
    Node* ptr = head->next;
    if (ptr != nullptr)
        ptr->prev = nullptr;
    else
        tail = nullptr;
    delete head;
    head = ptr;
    size--;
    beg.element = head;
}
void LinkedList::pop_back() {
    if (tail == NULL) return;

    Node* ptr = tail->prev;
    if (ptr != NULL)
        ptr->next = NULL;
    else
        head = NULL;
    delete tail;
    tail = ptr;
    size--;
    end.element = tail->next;
}
Node* LinkedList::getAt(int index) {
    Node* ptr = head;
    int n = 0;
    while (n != index) {
        if (ptr == NULL)
            return ptr;
        ptr = ptr->next;
        n++;
    }
    return ptr;
}
void LinkedList::insert(int index, int data) {
    Node* right = getAt(index);
    if (right == NULL)
        return push_back(data);
    Node* left = getAt(index - 1);
    if (left == NULL)
        return push_front(data);
    Node* ptr = new Node;
    ptr->data = data;
    ptr->next = right;
    left->next = ptr;
    size++;
}
void LinkedList::erase(int index) {
    Node* ptr = getAt(index);
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
    Node* left = getAt(index - 1);
    Node* right = ptr->next;
    left->next = right;
    delete ptr;
    size--;
}
LinkedList& LinkedList::operator=(const LinkedList& a) {
    if (this == &a) {
        return *this;
    }
    (*this).clear();
    Node* cur = a.head;
    while (cur != nullptr) {
        push_back(cur->data);
        cur = cur->next;
    }
    beg = a.beg;
    end = a.end;
    return *this;
}
int& LinkedList::operator[](int index) {
    if (index < size and index >= 0) {
        return getAt(index)->data;
    }
    else
        cout << size << "Ошибка! Нет элемента с таким индексом." << endl;
}
LinkedList LinkedList::operator+(LinkedList& c) {
    int size_temp = ((size > c.size) ? c.size : size);
    LinkedList temp;
    for (int i = 0; i < size_temp; i++){
        temp.push_back ((*this)[i] + c[i]);
    }
    temp.pop_front();
    beg = temp.beg;
    end = temp.end;
    return temp;
}
LinkedList LinkedList::operator+(int k) {
    int n = k;
    LinkedList temp;
    for (int i = 0; i < size; i++) {
        temp.push_back((*this)[i] + n);
    }
    temp.pop_front();
    beg.element = head;
    end.element = tail->next;
    return temp;
}
ostream& operator<<(ostream& out, const LinkedList& a) {
    out << endl << "Список: " << endl;
    Node* cur = a.head;
    while (cur != nullptr) {
        out << endl << "Элемент: ";
        out << cur->data << " ";
        cur = cur->next;
    }
    out << endl << "Конец списка!" << endl;
    return out;
}
istream& operator>>(istream& in, LinkedList& a) {
    cout << endl << "Список: " << endl;
    Node* cur = a.head;
    while (cur != nullptr) {
        in >> cur->data;
        cur = cur->next;
    }
    cout << endl << "Конец списка!" << endl;
    return in;
}