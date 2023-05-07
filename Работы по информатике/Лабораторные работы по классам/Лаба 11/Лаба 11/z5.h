#pragma once
#include <iostream>
#include <cstdlib>
#include <stack>
#include <iterator>
#include "LinkedList.h"
using namespace std;
class z5
{
public:
    LinkedList<double> Copy_to_list(stack<double> s)
    {
        LinkedList<double> l;
        while (!s.empty())
        {
            l.push_back(s.top());
            s.pop();
        }
        return l;
    }
    stack<double> Copy_to_stack(LinkedList<double> l)
    {
        stack<double> s;
        for (int i = 0; i < l.size; i++)
        {
            s.push(l[i]);
        }
        return s;
    }
    stack<double> make(int dequesize)
    {
        stack<double> s;
        double a;
        cout << "Введите элементы стека: \n";
        for (int i = 0; i < dequesize; i++) {
            cin >> a;
            s.push(a);
        }
        return s;
    }

    void print(stack<double> s)
    {
        LinkedList<double> l = Copy_to_list(s);
        cout << "\nСтек: \n";
        for (int i = 0; i < s.size(); i++)
        {
            cout << l[i] << " ";
        }
        cout << endl;
    }

    double max(stack<double> s)
    {
        LinkedList<double> l = Copy_to_list(s);
        double m = l[0];
        for (int i = 1; i < l.size; i++)
        {
            if (l[i] > m) m = l[i];
        }
        return m;
    }

    stack<double> push_back_list(stack<double> s, double el)
    {
        s.push(el);
        return s;
    }

    int* diap(stack<double> st, double f, double s)
    {
        LinkedList<double> l = Copy_to_list(st);
        int* mas = new int[l.size + 1];
        int k = 1;
        for (int i = 0; i < l.size; i++)
        {
            if (l[i] >= f && l[i] <= s) {
                mas[k] = i;
                k++;
            }
        }
        mas[0] = k;
        return mas;
    }

    stack<double> pop_el(stack<double> st, int* mas)
    {
        LinkedList<double> l = Copy_to_list(st);
        int n = mas[0];
        for (int i = 1; i < n; i++)
        {
            l.erase(mas[i]);
        }
        st = Copy_to_stack(l);
        return st;
    }

    double sred(stack<double> st)
    {
        LinkedList<double> l = Copy_to_list(st);
        double s = 0;
        int k = st.size();
        for (int i = 0; i < k; i++)
        {
            s += l[i];
        }
        return s / k;
    }

    stack<double> plus_const(stack<double> st, double s)
    {
        LinkedList<double> l = Copy_to_list(st);
        for (int i = 0; i < st.size(); i++)
        {
            l[i] += s;
        }
        st = Copy_to_stack(l);
        return st;
    }

    int main()
    {
        stack<double> myStack;
        int n;
        cout << "n = "; cin >> n;
        myStack = make(n);
        print(myStack);
        double el = max(myStack);
        myStack = push_back_list(myStack, el);
        print(myStack);
        double f, s;
        cout << "first = "; cin >> f;
        cout << "second = "; cin >> s;
        myStack = pop_el(myStack, diap(myStack, f, s));
        print(myStack);
        double sr = sred(myStack);
        myStack = plus_const(myStack, sr);
        print(myStack);
        return 0;
    }
};