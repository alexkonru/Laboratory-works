#include <iostream>
#include "LinkedList.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	try
	{
		LinkedList x(5);
		LinkedList y;
		cout << x;
		cout << "\nNumber?\n";
		int i;
		cin >> i;
		cout << x[i] << endl;
		y = x + 3;
		cout << y;
		x=x+y;
		cout << x;
	}
	catch (int)
	{
		cout << "ERROR!!!\n";
	}
	return 0;
}