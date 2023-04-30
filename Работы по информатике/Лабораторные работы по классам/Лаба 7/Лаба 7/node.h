#pragma once
template<class T>
class Node
{
public:
    T data;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
};