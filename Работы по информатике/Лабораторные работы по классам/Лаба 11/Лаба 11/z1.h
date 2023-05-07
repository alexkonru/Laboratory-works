#pragma once
#include <iostream>
#include <cstdlib>
#include <deque>
#include <iterator>
using namespace std;
class z1
{
public:
    deque<double> make(int dequesize)
    {
        deque<double> myDeque;
        double a;
        cout << "¬ведите элементы дека: \n";
        for (int i = 0; i < dequesize; i++) {
            cin >> a;
            myDeque.push_back(a);
        }
        return myDeque;
    }

    void print(deque<double> myDeque)
    {
        cout << "\n¬веденный дек: \n";
        if (!myDeque.empty()) {
            copy(myDeque.begin(), myDeque.end(), ostream_iterator<double>(cout, " "));
        }
        cout << endl;
    }

    double max(deque<double> myDeque)
    {
        double m = myDeque[0];
        for (int i = 1; i < myDeque.size(); i++)
        {
            if (myDeque[i] > m) m = myDeque[i];
        }
        return m;
    }

    deque<double> push_back_list(deque<double> myDeque, double el)
    {
        myDeque.push_back(el);
        return myDeque;
    }

    int* diap(deque<double> myDeque, double f, double s)
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

    deque<double> pop_el(deque<double> myDeque, int* mas)
    {
        int n = mas[0];
        for (int i = 1; i < n; i++)
        {
            myDeque.erase(myDeque.begin() + (mas[i] - (i - 1)));
        }
        return myDeque;
    }

    double sred(deque<double> myDeque)
    {
        double s = 0;
        int k = myDeque.size();
        for (int i = 0; i < k; i++)
        {
            s += myDeque[i];
        }
        return s / k;
    }

    deque<double> plus_const(deque<double> myDeque, double s)
    {
        for (int i = 0; i < myDeque.size(); i++)
        {
            myDeque[i] += s;
        }
        return myDeque;
    }

    int main()
    {
        deque<double> myDeque;
        deque<double>::iterator di = myDeque.begin();
        int n;
        cout << "n = "; cin >> n;
        myDeque = make(n);
        print(myDeque);
        double el = max(myDeque);
        myDeque = push_back_list(myDeque, el);
        print(myDeque);
        double f, s;
        cout << "first = "; cin >> f;
        cout << "second = "; cin >> s;
        myDeque = pop_el(myDeque, diap(myDeque, f, s));
        print(myDeque);
        double sr = sred(myDeque);
        myDeque = plus_const(myDeque, sr);
        print(myDeque);
        return 0;
    }
};

