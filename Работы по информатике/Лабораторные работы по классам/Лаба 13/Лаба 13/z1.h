#pragma once
#include <iostream>
#include <deque>
#include <algorithm>
#include <numeric>
#include "Pair.h"
using namespace std;
typedef deque<Pair>TDec;
typedef TDec::iterator it;

class z1
{
public:
    TDec make(double n)
    {
        TDec s;
        Pair a;
        for (double i = 0; i < n; i++)
        {
            cin >> a;
            s.push_back(a);
        }
        return s;
    }
    void print(TDec s)
    {
        if (s.size() > 0) {
            for_each(s.begin(), s.end(), [](Pair p) {
                cout << p << '\n';
                });
        }
        else {
            cout << "Список пуст!";
        }
        cout << '\n';
    }
    Pair max(TDec s)
    {
        Pair m = *max_element(s.begin(), s.end());
        return m;
    }

    TDec push_back_list(TDec s, Pair el)
    {
        s.push_back(el);
        return s;
    }


    TDec pop_el(TDec st, Pair f, Pair s)
    {
        auto i = remove_if(st.begin(), st.end(), [f, s](Pair p) {
            return ((f.first <= p.get_first() && p.get_first() <= s.first) || (f.second <= p.get_second() && p.get_second() <= s.second));
            });
        st.erase(i, st.end());
    }

    Pair sred(TDec st)
    {
        Pair Middle = accumulate(st.begin(), st.end(), Pair(0, 0));
        return Middle;
    }

    TDec plus_const(TDec st, Pair s)
    {
        for (Pair& c : st) {
            c + s;
        }
        return st;
    }

    int main()
    {
        TDec st;
        int n;
        cout << "n = "; cin >> n;
        st = make(n);
        print(st);
        Pair el = max(st);
        st = push_back_list(st, el);
        print(st);
        Pair f, s;
        cin >> f;
        cin >> s;
        st = pop_el(st, f, s);
        print(st);
        Pair sr = sred(st);
        st = plus_const(st, sr);
        print(st);
        return 0;
    }
};