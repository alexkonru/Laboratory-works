#pragma once
#include <iostream>
#include <set>
#include <list>
#include <algorithm>
#include <numeric>
#include "Pair.h"
using namespace std;
typedef set<Pair>TSt;
typedef list<Pair>Tl;
TSt::iterator it1;
Tl::iterator it2;

class z3
{
public:
    TSt to_set(Tl l)
    {
        TSt s;
        it2 = l.begin();
        int n = l.size();
        for (int i = 0; i < n; i++)
        {
            s.insert(*it2);
            it2++;
        }
        return s;
    }
    Tl to_list(TSt s)
    {
        Tl l;
        it1 = s.begin();
        for (int i = 0; i < s.size(); i++)
        {
            l.push_back(*it1);
            it1++;
        }
        return l;
    }
    TSt make(int n)
    {
        TSt s;
        Pair a;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            s.insert(a);
        }
        return s;
    }
    void print(TSt st)
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
    Pair max(TSt st)
    {
        Tl s = to_list(st);
        Pair m = *max_element(s.begin(), s.end());
        return m;
    }

    TSt push_back_list(TSt s, Pair el)
    {
        s.insert(el);
        return s;
    }

    TSt pop_el(TSt st, Pair f, Pair s)
    {
        Tl l = to_list(st);
        auto i = remove_if(l.begin(), l.end(), [f, s](Pair p) {
            return ((f.first <= p.get_first() && p.get_first() <= s.first) || (f.second <= p.get_second() && p.get_second() <= s.second));
            });
        l.erase(i, l.end());
        st = to_set(l);
        return st;
    }

    Pair sred(TSt st)
    {
        Tl l = to_list(st);
        Pair Middle = accumulate(l.begin(), l.end(), Pair(0, 0));
        return Middle;
    }

    TSt plus_const(TSt st, Pair s)
    {
        Tl l = to_list(st);
        for (Pair& c : l) {
            c + s;
        }
        st = to_set(l);
        return st;
    }

    int main()
    {
        TSt st;
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