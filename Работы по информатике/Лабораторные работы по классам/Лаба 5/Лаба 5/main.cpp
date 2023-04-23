#include "Object.h"
#include "Person.h"
#include "Employee.h"
#include "Vector.h"
#include <iostream>
using namespace std;

//void f1(Person& c)
//{
//	c.Set_name("Alex");
//	cout << c;
//}
//
//Person f2()
//{
//	Employee e("Mia", 26, "Engineer", 60.600);
//	return e;
//}

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