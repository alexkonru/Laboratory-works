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
void Person::Show()
{
	cout << "\nName: " << name;
	cout << "\nAge: " << age;
	cout << "\n";
}
void Person::Input()
{
	cout << "\nName: "; cin >> name;
	cout << "\nAge: "; cin >> age;
}
void Person::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)//событие-сообщение
	{
		switch (e.command)
		{
		case cmGet:cout << "Name = " << Get_name() << endl;
			break;
		}
	}
}