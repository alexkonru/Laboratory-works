#include "LinkedList.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int elem;
	LinkedList a(5);
	cout << endl << a << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Ёлемент: ";
		cin >> elem;
		a[i] = elem;
	}
	cout << endl << a << endl;
	LinkedList b(a);
	cout << endl << b << endl;
	b.push_back(10);
	b.erase(0);
	cout << endl << b << endl;
	LinkedList c(3);
	cout << endl << c << endl;
	LinkedList d = c + b;
	cout << endl << d << endl;
	d = d + 10;
	cout << endl << d << endl;
	cout << *(a.first()) << endl;
	Iterator i = a.first();
	++i;
	cout << *i << endl;
	for (i = a.first(); i != a.last(); ++i) cout << *i << endl;
	return 0;
}