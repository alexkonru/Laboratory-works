#pragma once
#include <iostream>
#include "LinkedList.h"
#include "Pair.h"
using namespace std;

class z3
{
public:
    LinkedList<Pair> make(double n)
    {
        LinkedList<Pair> s;
        Pair a;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            s.push_back(a);
        }
        return s;
    }
    void print(LinkedList<Pair> s)
    {
        for (int i = 0; i < s.size; i++)
        {
            cout << i << "  :  " << s[i] << " " << endl;
        }
    }
    Pair max(LinkedList<Pair> s)
    {
        Pair m = s[0];
        for (int i = 1; i < s.size; i++)
        {
            Pair a = s[i];
            if (a >= m) m = a;
        }
        return m;
    }

    LinkedList<Pair> push_back_list(LinkedList<Pair> s, Pair el)
    {
        s.push_back(el);
        return s;
    }

    int* diap(LinkedList<Pair> st, Pair f, Pair s)
    {
        int* mas = new int[st.size + 1];
        int k = 1;
        for (int i = 0; i < st.size; i++)
        {
            Pair a = st[i];
            if (a >= f && a <= s) {
                mas[k] = i;
                k++;
            }
        }
        mas[0] = k;
        return mas;
    }

    LinkedList<Pair> pop_el(LinkedList<Pair> st, int* mas)
    {
        int n = mas[0];
        for (int i = 1; i < n; i++)
        {
            st.erase(mas[i]);
        }
        return st;
    }

    Pair sred(LinkedList<Pair> st)
    {
        Pair s;
        int k = st.size;
        for (int i = 0; i < k; i++)
        {
            s = s + st[i];
        }
        return s / k;
    }

    LinkedList<Pair> plus_const(LinkedList<Pair> st, Pair s)
    {
        LinkedList<Pair> st2;
        for (int i = 0; i < st.size; i++)
        {
            st2.push_back(s + st[i]);
        }
        return st2;
    }

    int main()
    {
        LinkedList<Pair> st;
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
        st = pop_el(st, diap(st, f, s));
        print(st);
        Pair sr = sred(st);
        st = plus_const(st, sr);
        print(st);
        return 0;
    }
};