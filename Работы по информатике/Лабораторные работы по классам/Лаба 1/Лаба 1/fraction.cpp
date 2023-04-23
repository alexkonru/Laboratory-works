#include <iostream>
#include "fraction.h"
#include <cmath>
using namespace std;

void fraction::Init(int F, double S) {
	first = F; second = S;
}

void fraction::Show() {
	cout << "Целая часть числа: " << first << endl;
	cout << "Дробная часть числа: " << second << endl;
}

void fraction::Read() {
	cout << "Целая часть числа: " << endl; cin >> first;
	cout << "Дробная часть числа (в виде 0, ...): " << endl; cin >> second;
}

double fraction::make(double k) {
	return first * k + second * k;
}