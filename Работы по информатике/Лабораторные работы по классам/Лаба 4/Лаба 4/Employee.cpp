#include "Employee.h"
Employee::Employee(void) :Person()
{
	dol = "";
	okl = 0.0;
}
Employee::~Employee(void)
{

}
Employee::Employee(string n, int a, string d, double o) :Person(n, a)
{
	dol = d;
	okl = o;
}
Employee::Employee(const Employee& e)
{
	name = e.name;
	age = e.age;
	dol = e.dol;
	okl = e.okl;
}
void Employee::Set_dol(string d)
{
	dol = d;
}
void Employee::Set_okl(double o)
{
	okl = o;
}
Employee& Employee::operator=(const Employee& e)
{
	if (&e == this) return *this;
	name = e.name;
	age = e.age;
	dol = e.dol;
	okl = e.okl;
	return *this;
}
istream& operator>>(istream& in, Employee& e)
{
	cout << "\nName: "; in >> e.name;
	cout << "\nAge: "; in >> e.age;
	cout << "\nDoljnosty: "; in >> e.dol;
	cout << "\nOklad: "; in >> e.okl;
	return in;
}
ostream& operator<<(ostream& out, const Employee& e)
{
	out << "\nName: " << e.name;
	out << "\nAge: " << e.age;
	out << "\nDoljnosty: " << e.dol;
	out << "\nOklad: " << e.okl;
	out << "\n";
	return out;
}