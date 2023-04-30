#pragma once
#include <iostream>
using namespace std;
class Time
{
public:
	Time(void);
	Time(int, int);
	Time(const Time&);
	Time& operator=(const Time&);
	Time operator+(int k);
	friend ostream& operator<<(ostream& iut, const Time&);
	friend istream& operator>>(istream& in, Time&);
public:
	virtual ~Time(void) {};
private:
	int min, sec;
};

