#pragma once
#include<iostream>
using namespace std;
class Pair{
public:
	int first;
	double second;
public:
	Pair() { first = 0; second = 0.0; }
	Pair(int f, double s) { first = f; second = s; }
	Pair(const Pair& p) { first = p.first; second = p.second;}
	~Pair() {};
	int get_first() { return first; }
	double get_second() { return second; }
	void set_first(int f) { first = f; }
	void set_second(int s) { second = s; }
	Pair& operator=(const Pair&);
	friend bool operator<(const Pair& p1, const Pair& p2)
	{
		double temp1 = p1.first + p1.second;
		double temp2 = p2.first + p2.second;
		if (temp1 < temp2) return true;
		return false;
	}
	friend bool operator>(const Pair& p1, const Pair& p2)
	{
		double temp1 = p1.first + p1.second;
		double temp2 = p2.first + p2.second;
		if (temp1 > temp2) return true;
		return false;
	}
	bool operator<=(const Pair& );
	bool operator>=(const Pair& );
	Pair operator/(int el);
	Pair operator+(Pair el);
	Pair operator--(int);
	Pair& operator--();
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& t);

};
