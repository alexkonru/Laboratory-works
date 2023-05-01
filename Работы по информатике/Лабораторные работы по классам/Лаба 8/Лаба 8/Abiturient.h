#pragma once
#include "Person.h"
class Abiturient :
	public Person
{
public:
	Abiturient(void);
public:
	~Abiturient(void);
	void Show();
	void Input();
	Abiturient(string, int, int, string);
	Abiturient(const Abiturient&);
	int Get_count() { return count; }
	void Set_count(int);
	string Get_spec() { return spec; }
	void Set_spec(string);
	Abiturient& operator=(const Abiturient&);
protected:
	int count;
	string spec;
};

