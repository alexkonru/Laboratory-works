#pragma once
#include "Person.h"
class Employee :
	public Person
{
public:
	Employee(void);
public:
	~Employee(void);
	void Show();
	Employee(string, int, string, double);
	Employee(const Employee&);
	string Get_dol() { return dol; }
	void Set_dol(string);
	double Get_okl() { return okl; }
	void Set_okl(double);
	Employee& operator=(const Employee&);
	friend istream& operator>>(istream& in, Employee& e);
	friend ostream& operator<<(ostream& out, const Employee& e);
protected:
	string dol;
	double okl;
};

