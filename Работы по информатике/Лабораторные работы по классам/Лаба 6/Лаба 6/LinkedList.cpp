#include "LinkedList.h"
#include <iostream>
using namespace std;

    LinkedList::LinkedList(int s, int k) {
        size = s;
        Node* ptr = new Node;
        ptr->data = k;
        head = ptr;
        for (int i = 0; i < size - 1; i++) {
            Node* ptr = new Node;
            cout << "Элемент: ";
            cin >> k;
            push_back(k);
        }
    }
    LinkedList::LinkedList(const LinkedList& a) {
        Node* ptr = a.head;
        while (ptr != nullptr) {
            push_back(ptr->data);
            ptr = ptr->next;
        }
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
        head = ptr;
        size++;
    }
    void LinkedList::push_back(int data) {
        Node* ptr = new Node;
        ptr->data = data;
        ptr->next = NULL;
        if (head == NULL)
            head = ptr;
        else {
            Node* cur = head;
            while (cur->next != NULL) cur = cur->next;
            cur->next = ptr;
        }
        size++;
    }
    void LinkedList::pop_front() {
        if (head == NULL) return;
        Node* ptr = head->next;
        delete head;
        head = ptr;
        size--;
    }
    void LinkedList::pop_back() {
        if (head == NULL) return;
        Node* ptr = head;
        Node* cur = head;
        while (cur->next != NULL) { ptr = cur; cur = cur->next; }
        ptr->next = NULL;
        delete cur;
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
    LinkedList& LinkedList::operator=(const LinkedList& a) {
        if (this == &a) {
            return *this;
        }
        Node* ptr = head;
        while (ptr != nullptr) {
            head = ptr->next;
            delete ptr;
            ptr = head;
            size--;
        }
        Node* cur = a.head;
        while (cur != nullptr) {
            push_back(cur->data);
            cur = cur->next;
        }
        return *this;
    }
    int& LinkedList::operator[](int index) {
        if (index < size and index >= 0) {
            Node* ptr = new Node;
            ptr = getAt(index);
            return ptr->data;
        }
        else
            cout << "Ошибка! Нет элемента с таким индексом." << endl;
    }
    LinkedList LinkedList::operator+(LinkedList& a) {
        int size_temp = ((size > a.size) ? a.size : size);
        LinkedList temp(size_temp);
        for (int i = 0; i < size_temp; i++) {
            temp[i] = (*this)[i] + a[i];
        }
        return temp;
    }
    LinkedList LinkedList::operator+() {
        LinkedList temp(size);
        int n;
        cout << "Какое число добавить ко всем элементам?" << endl;
        cin >> n;
        for (int i = 0; i < size; i++) {
            temp[i] = (*this)[i] + n;
            return temp;
        }
    }
    ostream& operator<<(ostream& out, const LinkedList & a) {
        out << endl << "Список: " << endl;
        Node* cur = a.head;
        while (cur != nullptr) {
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