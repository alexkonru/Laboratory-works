#include "LinkedList.h"
#include "Time.h"
#include "node.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	LinkedList<int>A(5, 0);
	cin >> A;
	cout << A;
	return 0;
}