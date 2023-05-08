#include "Object.h"
#include "Person.h"
#include "Employee.h"
#include "Vector.h"
#include <iostream>
using namespace std;


int main()
{
	Vector v(2);
	Person a;
	cin >> a;
	Employee b;
	cin >> b;
	Object* p = &a;
	v.Add(p);
	p = &b;
	v.Add(p);
	cout << v;
	return 0;
}