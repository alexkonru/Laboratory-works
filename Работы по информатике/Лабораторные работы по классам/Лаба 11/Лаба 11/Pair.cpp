#include <iostream>
#include "Pair.h"
using namespace std;

Pair& Pair::operator=(const Pair& p) {
	if (&p == this) return *this;
	first = p.first;
	second = p.second;
	return *this;
}
Pair& Pair::operator+(const Pair& p)
{
	first += p.first;
	second += p.second;
	return *this;
}
Pair& Pair::operator/(int k)
{
	first /= k;
	second /= k;
	return *this;
}
Pair& Pair::operator--() {
	first=first-1;
	return *this;
}
Pair Pair::operator--(int) {
	double temp = second;
	Pair p(first, second);
	second = temp - 1;
	return p;
}
bool Pair::operator<=(const Pair& p) {
	double temp1 = first + second;
	double temp2 = p.first + p.second;
	if (temp1 <= temp2) return true;
	return false;
}
bool Pair::operator>=(const Pair& p) {
	double temp1 = first + second;
	double temp2 = p.first + p.second;
	if (temp1 >= temp2) return true;
	return false;
}
istream& operator>>(istream& in, Pair& p) {
	cout << "First = "; in >> p.first;
	cout << "Second = "; in >> p.second;
	return in;
}
ostream& operator<<(ostream& out, const Pair& p) {
	return (out << p.first << " : " << p.second);
}