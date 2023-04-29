#include <iostream>
#include "LinkedList.h"
#include "error.h"
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
	catch (error e)
	{
		e.what();
	}
	return 0;
}