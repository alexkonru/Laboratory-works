#include "Abiturient.h"
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

Abiturient make_abiturient() {
	string f, s;
	int c;
	cout << "���: ";
	getline(cin, f);
	cout << "�������������: ";
	getline(cin, s);
	cout << "���������� ������: ";
	cin >> c;
	Abiturient a(f, s, c);
	return a;
}
void print_abiturient(Abiturient a) {
	a.show();
}
int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Abiturient a1;
	a1.show();
	Abiturient a2("������ ������� ��������", "�������-�������������", 250);
	a2.show();
	Abiturient a3 = a2;
	a3.set_fio("����� �������� ��������");
	a3.set_spec("�����������");
	a3.set_count(260);
	print_abiturient(a3);
	a1 = make_abiturient();
	a1.show();
}