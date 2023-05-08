#pragma once
#include <iostream>
#include <set>
#include "Pair.h"
using namespace std;
typedef set<Pair>Tst;

class z3
{
public:
    TSt make(double n)
    {
        TSt s;
        Pair a;
        for (double i = 0; i < n; i++)
        {
            cin >> a;
            s.push(a);
        }
        return s;
    }
    void print(TSt s)
    {
        TSt s2 = s;
        for (double i = 0; i < s.size(); i++)
        {
            cout << s2.top() << " " << endl;
            s2.pop();
        }
    }
    Pair max(TSt s)
    {
        TSt s2 = s;
        Pair m = s2.top();
        s2.pop();
        for (int i = 1; i < s.size(); i++)
        {
            Pair a = s2.top();
            if (a >= m) m = a;
            s2.pop();
        }
        return m;
    }

    TSt push_back_list(TSt s, Pair el)
    {
        s.push(el);
        return s;
    }

    TSt pop_el(TSt st, Pair f, Pair s)
    {
        TSt s2;
        for (int i = 0; i < st.size(); i++)
        {
            if (st.top() >= f && st.top() <= s) s2.push(st.top());
            st.pop();
        }
        return s2;
    }

    Pair sred(TSt st)
    {
        TSt s2 = st;
        Pair s;
        int k = st.size();
        for (int i = 0; i < k; i++)
        {
            s = s + s2.top();
            s2.pop();
        }
        return s / k;
    }

    TSt plus_const(TSt st, Pair s)
    {
        TSt st2;
        for (int i = 0; i < st.size(); i++)
        {
            st2.push(s + st.top());
            st.pop();
        }
        return st2;
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