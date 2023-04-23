#include <iostream>
#include "Pair.h"
using namespace std;

int main() {
	Pair a;
	Pair b;
	Pair c;
	cin >> a;
	cin >> b;
	--a;
	cout << a << endl;
	cout << ((a--) < b) << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << (a > b) << endl;
	return 0;
}