#include "Person.h"
Person::Person(void)
{
	name = "";
	age = 0;
}
Person::~Person(void) 
{

}
Person::Person(string n, int a)
{
	name = n;
	age = a;
}
Person::Person(const Person& person)
{
	name = person.name;
	age = person.age;
}
void Person::Set_name(string n)
{
	name = n;
}
void Person::Set_age(int a)
{
	age = a;
}
Person& Person::operator=(const Person& p)
{
	if (&p == this) return *this;
	name = p.name;
	age = p.age;
	return *this;
}
istream& operator>>(istream& in, Person& p)
{
	cout << "\nName: "; in >> p.name;
	cout << "\nAge: "; in >> p.age;
	return in;
}
ostream& operator<<(ostream& out,const Person& p)
{
	out << "\nName: " << p.name;
	out << "\nAge: " << p.age;
	out << "\n";
	return out;
}
void Person::Show()
{
	cout << "\nName: " << name;
	cout << "\nAge: " << age;
	cout << "\n";
}