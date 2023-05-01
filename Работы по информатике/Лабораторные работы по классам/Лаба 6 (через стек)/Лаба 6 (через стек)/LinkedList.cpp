#include "LinkedList.h"
#include <iostream>
using namespace std;
LinkedList::LinkedList() {
    push_back(0);
    beg.element = head;
    end.element = getAt(size-1)->next;
}
LinkedList::LinkedList(int s) {
    int n;
    for (int i = 0; i < s; i++) {
        cout << "Элемент: ";
        cin >> n;
        push_back(n);
    }
    beg.element = head;
    end.element = getAt(size - 1)->next;
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
    while (head != nullptr)
        pop_back();
    size = 0;
}
void LinkedList::push_back(int data) {
    Node* ptr = new Node;
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    getAt(size)->next = nullptr;
    size++;
    end.element = getAt(size - 1)->next;
}
void LinkedList::pop_back() {
    if (head == nullptr) return;
    Node* ptr = head->next;
    delete head;
    head = ptr;    
    size--;
    end.element = getAt(size - 1);
}
Node* LinkedList::getAt(int index) {
    Node* ptr = head;
    int n = 0;
    while (n != index) {
        if (ptr == nullptr)
            return ptr;
        ptr = ptr->next;
        n++;
    }
    return ptr;
}
void LinkedList::insert(int index, int data) {
    if (index >= size)
        return push_back(data);
    else {
        Node* ptr = new Node;
        ptr->data = data;
        Node* t = head;
        Node* cur = t;
        head2 = t;
        for (int i = size - 1; i > index; i--) {
            t = t->next;
            Node* cur = new Node;
            cur->data = t->data;
            cur->next = head2;
            head2 = cur;
        }
        t = t->next;
        head = ptr;
        for (int i = index; i < size; i++) {
            cur = new Node;
            cur->data = head2->data;
            cur->next = head;
            head = cur;
            head2 = head2->next;
        }
        if (index == 0) ptr->next = nullptr;
        else ptr->next = t;
    }
    size++;
}
void LinkedList::erase(int index) {
    if (head == nullptr)
        return;
    if (index == size - 1) {
        pop_back();
        return;
    }
    Node* t = head;
    Node* cur = t;
    head2 = t;
    for (int i = size - 2; i > index; i--) {
        t = t->next;
        Node* cur = new Node;
        cur->data = t->data;
        cur->next = head2;
        head2 = cur;
    }
    t = t->next;
    head = t->next;
    for (int i = index + 1; i < size; i++) {
        cur = new Node;
        cur->data = head2->data;
        cur->next = head;
        head = cur;
        head2 = head2->next;
    }
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
    temp.erase(0);
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
    temp.erase(0);
    beg.element = head;
    end.element = getAt(size - 1)->next;
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