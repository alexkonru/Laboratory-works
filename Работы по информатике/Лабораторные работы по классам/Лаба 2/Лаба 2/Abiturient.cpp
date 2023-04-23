#include "Abiturient.h"
#include <iostream>
#include <string>
using namespace std;

Abiturient::Abiturient() {
	fio = "";
	spec = "";
	count = 0;
	cout << "����������� ��� ���������� ��� ������� " << this << endl << endl;
}
Abiturient::Abiturient(string f, string s, int c) {
	fio = f;
	spec = s;
	count = c;
	cout << "����������� � ����������� ��� ������� " << this << endl << endl;
}
Abiturient::Abiturient(const Abiturient &a) {
	fio = a.fio;
	spec = a.spec;
	count = a.count;
	cout << "����������� ����������� ��� ������� " << this << endl << endl;
}
Abiturient::~Abiturient() {
	cout << "���������� ��� ������� " << this << endl;
}
string Abiturient::get_fio() {
	return fio;
}
string Abiturient::get_spec() {
	return spec;
}
int Abiturient::get_count() {
	return count;
}
void Abiturient::set_fio(string f) {
	fio = f;
}
void Abiturient::set_spec(string s) {
	spec = s;
}
void Abiturient::set_count(int c) {
	count = c;
}
void Abiturient::show() {
	cout << "���: " << fio << endl;
	cout << "�������������: " << spec << endl;
	cout << "���������� �����: " << count << endl;
}