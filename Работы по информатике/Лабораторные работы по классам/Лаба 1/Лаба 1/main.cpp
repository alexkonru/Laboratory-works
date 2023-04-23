#include "fraction.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#pragma warning(disable : 4996)
using namespace std;
fraction makeFraction(int, double);
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	fraction A;
	A.Init(12, 0.7);
	A.Show();
	cout << "k = 3.4" << endl;
	cout << A.make(3.4) << endl;
	cout << "Press Enter..." << endl;
	getch();
	fraction B;
	B.Read();
	B.Show();
	double k;
	cout << "k =  ";
	cin >> k;
	cout << B.make(k) << endl;
	cout << "Press Enter..." << endl;
	getch();
	fraction* X = new fraction;
	X->Init(2, 0.3);
	X->Show();
	cout << "k = 3.8" << endl;
	cout << X->make(3.8) << endl;
	cout << "Press Enter..." << endl;
	getch();
	fraction mas[3];
	for (int i = 0; i < 3; i++) mas[i].Read();
	for (int i = 0; i < 3; i++) mas[i].Show();
	for (int i = 0; i < 3; i++) {
		cout << "k = ";
		cin >> k;
		mas[i].make(k);
	}
	cout << "Press Enter..." << endl;
	getch();
	fraction* p_mas = new fraction[3];
	for (int i = 0; i < 3; i++) p_mas[i].Read();
	for (int i = 0; i < 3; i++) p_mas[i].Show();
	for (int i = 0; i < 3; i++) {
		cout << "k = "; cin >> k;
		cout << mas[i].make(k) << endl;
	}
	cout << "Press Enter..." << endl;
	getch();
	double y; int z;
	cout << "Целая часть числа: "; cin >> y;
	cout << "Дробная часть числа: "; cin >> z;
	fraction F = makeFraction(y, z);
	F.Show();
	cout << F.make(k) << endl;
	return 0;
}
fraction makeFraction(int f, double s) {
	fraction t;
	t.Init(f, s);
	return t;
}