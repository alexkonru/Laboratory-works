#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
    size = 0;
}
LinkedList::LinkedList(int s) {
    if (s > max_size) throw 1;
    size = s;
    for (int i = 0; i < s; i++) {
        push_back(0);
    }
}
LinkedList::LinkedList(const LinkedList& l) {
    Node* ptr = l.head;
    while (ptr != nullptr) {
        push_back(ptr->data);
        ptr = ptr->next;
    }
}
LinkedList::~LinkedList() {
    clear();
}
LinkedList::LinkedList(int s, int* mas) {
    if (s > max_size) throw 1;
    size = s;
    for (int i = 0; i < size; i++) {
        push_back(mas[i]);
    }
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
const LinkedList& LinkedList::operator=(const LinkedList& l)
{
    if (this == &l) return *this;
    if (head != nullptr) clear();
    size = l.size;
    Node* cur = l.head;
    while (cur != nullptr) {
        push_back(cur->data);
        cur = cur->next;
    }
}
ostream& operator<<(ostream& out, const LinkedList& l)
{
    if (l.size == 0) out << "Empty\n";
    else
    {
        Node* cur = l.head;
        while (cur != nullptr) {
            out << endl << "Ёлемент: ";
            out << cur->data << " ";
            cur = cur->next;
        }
    }
    return out;
}
istream& operator>>(istream& in, LinkedList& l)
{
    Node* cur = l.head;
    while (cur != nullptr) {
        in >> cur->data;
        cur = cur->next;
    }
    return in;
}
int LinkedList::operator[](int i)
{
    if (i < 0) throw 2;
    if (i >= size) throw 3;
    return getAt(i)->data;
}
LinkedList LinkedList::operator+(int a)
{
    if (size + 1 == max_size) throw 4;
    push_front(a);
    return *this;
}
LinkedList LinkedList::operator+(LinkedList& l)
{
    if (head == nullptr && l.head == nullptr) throw 5;
    for (int i = 0; i < l.size; i++)
    {
        push_back(l[i]);
    }
    return *this;
}