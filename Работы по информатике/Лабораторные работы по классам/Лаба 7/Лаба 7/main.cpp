#include "LinkedList.h"
#include "Pair.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	LinkedList<int>A(5,0);
	cin >> A;
	cout << A << endl;
	LinkedList<int>B(10, 1);
	cout << B << endl;
	B = A;
	cout << B << endl;
	cout << A[2] << endl;
	cout << A + B;
	B = A + 10;
	cout << B;
	Pair p;
	cin >> p;
	cout << p;
	LinkedList<Pair>C(5, p);
	cin >> C;
	cout << C << endl;
	LinkedList<Pair>D(2, p);
	cout << D << endl;
	D = C;
	cout << D << endl;
	cout << C[2] << endl;
	cout << C + D << endl;
	D = C + p;
	cout << D << endl;
	return 0;
}