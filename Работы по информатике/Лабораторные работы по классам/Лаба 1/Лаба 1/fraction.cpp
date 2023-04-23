#include <iostream>
#include "fraction.h"
#include <cmath>
using namespace std;

void fraction::Init(int F, double S) {
	first = F; second = S;
}

void fraction::Show() {
	cout << "����� ����� �����: " << first << endl;
	cout << "������� ����� �����: " << second << endl;
}

void fraction::Read() {
	cout << "����� ����� �����: " << endl; cin >> first;
	cout << "������� ����� ����� (� ���� 0, ...): " << endl; cin >> second;
}

double fraction::make(double k) {
	return first * k + second * k;
}