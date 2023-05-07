#pragma once
#include <iostream>
#include <set>
#include "Pair.h"
using namespace std;
typedef set<double>TSet;
typedef TSet::iterator it;

class z2
{
public:
    TSet make(double n)
    {
        TSet s;
        Pair a;
        for (double i = 0; i < n; i++)
        {
            cin >> a;
            s.insert(a.first + a.second);
        }
        return s;
    }
    void print(TSet s)
    {
        TSet::iterator it = s.begin();
        for (double i = 0; i < s.size(); i++)
        {
            cout << i << " : " << *it << " " << endl;
            it++;
        }
    }
    double max(TSet s)
    {
        TSet::iterator it = s.begin();
        double m = *it;
        for (int i = 1; i < s.size(); i++)
        {
            double a = *it;
            if (a >= m) m = a;
            it++;
        }
        return m;
    }

    TSet push_back_list(TSet s, double el)
    {
        s.insert(el);
        return s;
    }

    TSet pop_el(TSet st, Pair f, Pair s)
    {
        TSet::iterator it = st.begin();
        for (int i = 1; i < st.size(); i++)
        {
            if (*it >= (f.first + f.second) && *it <= (s.first + s.second)) st.erase(it);
            it++;
        }
        return st;
    }

    double sred(TSet st)
    {
        TSet::iterator it = st.begin();
        double s = 0.0;
        int k = st.size();
        for (int i = 0; i < k; i++)
        {
            s = s + *it;
            it++;
        }
        return s / k;
    }

    TSet plus_const(TSet st, double s)
    {
        TSet::iterator it = st.begin();
        TSet st2;
        for (int i = 0; i < st.size(); i++)
        {
            st2.insert(s + *it);
            it++;
        }
        return st2;
    }

    int main()
    {
        TSet st;
        int n;
        cout << "n = "; cin >> n;
        st = make(n);
        print(st);
        double el = max(st);
        st = push_back_list(st, el);
        print(st);
        Pair f, s;
        cin >> f;
        cin >> s;
        st = pop_el(st, f, s);
        print(st);
        double sr = sred(st);
        st = plus_const(st, sr);
        print(st);
        return 0;
    }
};