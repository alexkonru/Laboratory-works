#pragma once
#include <iostream>
#include <cstdlib>
#include <deque>
#include <iterator>
#include "Pair.h"
using namespace std;
class z2
{
public:
    deque<Pair> make(int dequesize)
    {
        deque<Pair> myDeque;
        Pair a;
        cout << "¬ведите элементы дека: \n";
        for (int i = 0; i < dequesize; i++) {
            cin >> a;
            myDeque.push_back(a);
        }
        return myDeque;
    }

    void print(deque<Pair> myDeque)
    {
        cout << "\n¬веденный дек: \n";
        if (!myDeque.empty()) {
            copy(myDeque.begin(), myDeque.end(), ostream_iterator<Pair>(cout, " "));
        }
        cout << endl;
    }

    Pair max(deque<Pair> myDeque)
    {
        Pair m = myDeque[0];
        for (int i = 1; i < myDeque.size(); i++)
        {
            if (myDeque[i] >= m) m = myDeque[i];
        }
        return m;
    }

    deque<Pair> push_back_list(deque<Pair> myDeque, Pair el)
    {
        myDeque.push_back(el);
        return myDeque;
    }

    int* diap(deque<Pair> myDeque, Pair f, Pair s)
    {
        int* mas = new int[myDeque.size() + 1];
        int k = 1;
        for (int i = 0; i < myDeque.size(); i++)
        {
            if (myDeque[i] >= f && myDeque[i] <= s) {
                mas[k] = i;
                k++;
            }
        }
        mas[0] = k;
        return mas;
    }

    deque<Pair> pop_el(deque<Pair> myDeque, int* mas)
    {
        int n = mas[0];
        for (int i = 1; i < n; i++)
        {
            myDeque.erase(myDeque.begin() + (mas[i] - (i - 1)));
        }
        return myDeque;
    }

    Pair sred(deque<Pair> myDeque)
    {
        Pair s;
        int k = myDeque.size();
        for (int i = 0; i < k; i++)
        {
            s = s + myDeque[i];
        }
        return s / k;
    }

    deque<Pair> plus_const(deque<Pair> myDeque, Pair s)
    {
        for (int i = 0; i < myDeque.size(); i++)
        {
            myDeque[i] = myDeque[i] + s;
        }
        return myDeque;
    }

    Pair& operator=(const Pair& p) {
        Pair P;
        P.first = p.first;
        P.second = p.second;
        return P;
    }

    int main()
    {
        deque<Pair> myDeque;
        deque<Pair>::iterator di = myDeque.begin();
        int n;
        cout << "n = "; cin >> n;
        myDeque = make(n);
        print(myDeque);
        Pair el = max(myDeque);
        myDeque = push_back_list(myDeque, el);
        print(myDeque);
        Pair f, s;
        cout << "first = "; cin >> f;
        cout << "second = "; cin >> s;
        myDeque = pop_el(myDeque, diap(myDeque, f, s));
        print(myDeque);
        Pair sr = sred(myDeque);
        myDeque = plus_const(myDeque, sr);
        print(myDeque);
        return 0;
    }
};