#include "Person.h"
#include "Employee.h"
#include<iostream>
using namespace std;

void f1(Person& c)
{
	c.Set_name("Alex");
	cout << c;
}

Person f2()
{
	Employee e("Mia", 26, "Engineer", 60.600);
	return e;
}

int main()
{
	Person a;
	cin >> a;
	cout << a;
	Person b("Tom", 20);
	cout << b;
	a = b;
	cout << a;
	Employee c;
	cin >> c;
	cout << c;
	f1(c);
	a = f2();
	cout << a;
	return 0;
}