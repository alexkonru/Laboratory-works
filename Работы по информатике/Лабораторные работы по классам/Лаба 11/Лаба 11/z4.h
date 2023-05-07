#pragma once
#include <iostream>
#include <cstdlib>
#include <stack>
#include <iterator>
#include <vector>
using namespace std;
class z4
{
public:
    vector<double> Copy_to_list(stack<double> s)
    {
        vector<double> v;
        while (!s.empty())
        {
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }
    stack<double> Copy_to_stack(vector<double> v)
    {
        stack<double> s;
        for (int i=0; i<v.size(); i++)
        {
            s.push(v[i]);
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
        vector<double> v = Copy_to_list(s);
        cout << "\nСтек: \n";
        for (int i=0; i<s.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    double max(stack<double> s)
    {
        vector<double> v = Copy_to_list(s);
        double m = v[0];
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] > m) m = v[i];
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
        vector<double> v = Copy_to_list(st);
        int* mas = new int[v.size() + 1];
        int k = 1;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] >= f && v[i] <= s) {
                mas[k] = i;
                k++;
            }
        }
        mas[0] = k;
        return mas;
    }

    stack<double> pop_el(stack<double> st, int* mas)
    {
        vector<double> v = Copy_to_list(st);
        int n = mas[0];
        for (int i = 1; i < n; i++)
        {
            v.erase(v.begin() + (mas[i] - (i - 1)));
        }
        st = Copy_to_stack(v);
        return st;
    }

    double sred(stack<double> st)
    {
        vector<double> v = Copy_to_list(st);
        double s = 0;
        int k = st.size();
        for (int i = 0; i < k; i++)
        {
            s += v[i];
        }
        return s / k;
    }

    stack<double> plus_const(stack<double> st, double s)
    {
        vector<double> v = Copy_to_list(st);
        for (int i = 0; i < st.size(); i++)
        {
            v[i] += s;
        }
        st = Copy_to_stack(v);
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