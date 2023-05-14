#pragma once
#include <iostream>
#include <stack>
#include <list>
#include <algorithm>
#include <numeric>
#include "Pair.h"
using namespace std;
typedef stack<Pair>Tst;
typedef list<Pair>Tl;

class z2
{
public:
    Tst to_stack(Tl l)
    {
        Tst s;
        Tl::iterator it = l.begin();
        int n = l.size();
        for (int i = 0; i < n; i++)
        {
            s.push(*it);
            it++;
        }
        return s;
    }
    Tl to_list(Tst s)
    {
        Tl l;
        for (int i = 0; i < s.size(); i++)
        {
            l.push_back(s.top());
            s.pop();
        }
        return l;
    }
    Tst make(double n)
    {
        Tst s;
        Pair a;
        for (double i = 0; i < n; i++)
        {
            cin >> a;
            s.push(a);
        }
        return s;
    }
    void print(Tst st)
    {
        Tl s = to_list(st);
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
    Pair max(Tst st)
    {
        Tl s = to_list(st);
        Pair m = *max_element(s.begin(), s.end());
        return m;
    }

    Tst push_back_list(Tst s, Pair el)
    {
        s.push(el);
        return s;
    }

    Tst pop_el(Tst st, Pair f, Pair s)
    {
        Tl l = to_list(st);
        auto i = remove_if(l.begin(), l.end(), [f, s](Pair p) {
            return ((f.first <= p.get_first() && p.get_first() <= s.first) || (f.second <= p.get_second() && p.get_second() <= s.second));
            });
        l.erase(i, l.end());
        st = to_stack(l);
        return st;
    }

    Pair sred(Tst st)
    {
        Tl l = to_list(st);
        Pair Middle = accumulate(l.begin(), l.end(), Pair(0, 0));
        return Middle;
    }

    Tst plus_const(Tst st, Pair s)
    {
        Tl l = to_list(st);
        for (Pair& c : l) {
            c + s;
        }
        st = to_stack(l);
        return st;
    }

    int main()
    {
        Tst st;
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