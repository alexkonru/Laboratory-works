#include <iostream>
#include "Pair.h"
#include "LinkedList.h"
using namespace std;

Pair& Pair::operator=(const Pair& p) {
	if (&p == this) return *this;
	first = p.first;
	second = p.second;
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
bool Pair::operator<(const Pair& p) {
	double temp1 = first + second;
	double temp2 = p.first + p.second;
	if (temp1 < temp2) return true;
	return false;
}
bool Pair::operator>(const Pair& p) {
	double temp1 = first + second;
	double temp2 = p.first + p.second;
	if (temp1 > temp2) return true;
	return false;
}
Pair Pair::operator+(Pair k) {
	double t1 = first + k.first;
	double t2 = second + k.second;
	Pair temp(t1, t2);
	return temp;
}
istream& operator>>(istream& in, Pair& p) {
	cout << "First = "; in >> p.first;
	cout << "Second = "; in >> p.second;
	return in;
}
ostream& operator<<(ostream& out, const Pair& p) {
	return (out << p.first << " : " << p.second);
}