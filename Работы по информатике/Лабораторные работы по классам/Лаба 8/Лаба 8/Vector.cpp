#include "Vector.h"
#include "Person.h"
#include "Abiturient.h"
#include "Event.h"
#include "Object.h"
Vector::~Vector(void)
{
	if (beg != 0) delete[] beg;
	beg = 0;
}
Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
void Vector::Add()
{
	cout << "1. Person" << endl;
	cout << "2. Abiturient" << endl;
	int y;
	cin >> y;
	if (y == 1)
	{
		Person* a = new (Person);
		a->Input();
		Person* p = a;
		if (cur < size)
		{
			beg[cur] = p;
			cur++;
		}
	}
	else
		if (y == 2)
		{
			Abiturient* b = new Abiturient;
			b->Input();
			Person* p = b;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else return;
}
void Vector::Show()
{
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();
		p++;
	}
}
int Vector::operator ()()
{
	return cur;
}
void Vector::Del()
{
	if (cur == 0) return;
	cur--;
}
void Vector::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e);//вызов метода (позднее связывание)
			p++;//передвигаем указатель на следующий объект
		}
	}
}