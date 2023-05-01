#include "Abiturient.h"
Abiturient::Abiturient(void) :Person()
{
	count = 0;
	spec = "";
}
Abiturient::~Abiturient(void)
{

}
Abiturient::Abiturient(string n, int a, int c, string s) :Person(n, a)
{
	count = c;
	spec = s;
}
Abiturient::Abiturient(const Abiturient& e)
{
	name = e.name;
	age = e.age;
	count = e.count;
	spec = e.spec;
}
void Abiturient::Set_count(int c)
{
	count = c;
}
void Abiturient::Set_spec(string s)
{
	spec = s;
}
Abiturient& Abiturient::operator=(const Abiturient& e)
{
	if (&e == this) return *this;
	name = e.name;
	age = e.age;
	count = e.count;
	spec = e.spec;
	return *this;
}
void Abiturient::Show()
{
	cout << "\nName: " << name;
	cout << "\nAge: " << age;
	cout << "\nCount: " << count;
	cout << "\nSpec: " << spec;
	cout << "\n";
}
void Abiturient::Input()
{
	cout << "\nName: "; cin >> name;
	cout << "\nAge: "; cin >> age;
	cout << "\nCount: "; cin >> count;
	cout << "\nSpec: "; cin >> spec;
	cout << "\n";
}