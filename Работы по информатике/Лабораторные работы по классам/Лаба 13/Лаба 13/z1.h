#pragma once
#include <iostream>
#include <deque>
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
        TDec::iterator it = s.begin();
        for (double i = 0; i < s.size(); i++)
        {
            cout << i << " : " << *it << " " << endl;
            it++;
        }
    }
    Pair max(TDec s)
    {
        TDec::iterator it = s.begin();
        Pair m = *it;
        for (int i = 1; i < s.size(); i++)
        {
            Pair a = *it;
            if (a >= m) m = a;
            it++;
        }
        return m;
    }

    TDec push_back_list(TDec s, Pair el)
    {
        s.push_back(el);
        return s;
    }


    TDec pop_el(TDec st, Pair f, Pair s)
    {
        TDec::iterator it = st.begin();
        for (int i = 1; i < st.size(); i++)
        {
            if (*it >= f && *it <= s) st.erase(it);
            it++;
        }
        return st;
    }

    Pair sred(TDec st)
    {
        TDec::iterator it = st.begin();
        Pair s;
        int k = st.size();
        for (int i = 0; i < k; i++)
        {
            s = s + *it;
            it++;
        }
        return s / k;
    }

    TDec plus_const(TDec st, Pair s)
    {
        TDec::iterator it = st.begin();
        TDec st2;
        for (int i = 0; i < st.size(); i++)
        {
            st2.push_back(s + *it);
            it++;
        }
        return st2;
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