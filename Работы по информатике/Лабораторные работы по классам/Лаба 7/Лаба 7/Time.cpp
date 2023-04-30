#include "Time.h"
#include <iostream>
using namespace std;
Time::Time(void)
{
	min = sec = 0;
}
Time::Time(int M, int S)
{
	min = M;
	sec = S;
}
Time::Time(const Time& t)
{
	min = t.min;
	sec = t.sec;
}
Time& Time::operator=(const Time& t)
{
	min = t.min;
	sec = t.sec;
	return *this;
}
Time Time::operator+(int k)
{
	int t = min * 60 + sec;
	t += k;
	Time temp(t / 60, t % 60);
	return temp;
}
ostream& operator<<(ostream& out, const Time& t)
{
	out << t.min << " : " << t.sec;
	return out;
}
istream& operator>>(istream& in, Time& t)
{
	cout << "\nmin?\n";
	in >> t.min;
	cout << "\nsec ?\n";
	in >> t.sec;
	return in;
}