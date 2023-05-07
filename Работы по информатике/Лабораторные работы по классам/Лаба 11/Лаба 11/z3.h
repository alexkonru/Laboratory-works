#pragma once
#include <iostream>
#include <cstdlib>
#include <iterator>
#include "LinkedList.h"
using namespace std;
class z3
{
public:
    LinkedList<Pair> make(int dequesize)
    {
        LinkedList<Pair> myList;
        Pair a;
        cout << "¬ведите элементы дека: \n";
        for (int i = 0; i < dequesize; i++) {
            cin >> a;
            myList.push_back(a);
        }
        return myList;
    }

    void print(LinkedList<Pair> myList)
    {
        cout << "\n¬веденный дек: \n";
        for(int i=0; i<myList.size; i++)
        {
            cout << myList[i] << " ";
        }
        cout << endl;
    }

    Pair max(LinkedList<Pair> myList)
    {
        Pair m = myList[0];
        for (int i = 1; i < myList.size; i++)
        {
            if (myList[i] >= m) m = myList[i];
        }
        return m;
    }

    LinkedList<Pair> push_back_list(LinkedList<Pair> myList, Pair el)
    {
        myList.push_back(el);
        return myList;
    }

    int* diap(LinkedList<Pair> myList, Pair f, Pair s)
    {
        int* mas = new int[myList.size + 1];
        int k = 1;
        for (int i = 0; i < myList.size; i++)
        {
            if (myList[i] >= f && myList[i] <= s) {
                mas[k] = i;
                k++;
            }
        }
        mas[0] = k;
        return mas;
    }

    LinkedList<Pair> pop_el(LinkedList<Pair> myList, int* mas)
    {
        int n = mas[0];
        for (int i = 1; i < n; i++)
        {
            myList.erase(mas[i]);
        }
        return myList;
    }

    Pair sred(LinkedList<Pair> myList)
    {
        Pair s;
        int k = myList.size;
        for (int i = 0; i < k; i++)
        {
            s = s + myList[i];
        }
        return s / k;
    }

    LinkedList<Pair> plus_const(LinkedList<Pair> myList, Pair s)
    {
        for (int i = 0; i < myList.size; i++)
        {
            myList[i] = myList[i] + s;
        }
        return myList;
    }

    Pair& operator=(const Pair& p) {
        Pair P;
        P.first = p.first;
        P.second = p.second;
        return P;
    }
	int main()
	{
        LinkedList<Pair> myList;
        int n;
        cout << "n = "; cin >> n;
        myList = make(n);
        print(myList);
        Pair el = max(myList);
        myList = push_back_list(myList, el);
        print(myList);
        Pair f, s; 
        cin >> f;
        cin >> s;
        myList = pop_el(myList, diap(myList, f, s));
        print(myList);
        Pair sr = sred(myList);
        myList = plus_const(myList, sr);
        print(myList);
		return 0;
	}
};