#include "Abiturient.h"
#include <iostream>
#include <string>
using namespace std;

Abiturient::Abiturient() {
	fio = "";
	spec = "";
	count = 0;
	cout << "Конструктор без параметров для объекта " << this << endl << endl;
}
Abiturient::Abiturient(string f, string s, int c) {
	fio = f;
	spec = s;
	count = c;
	cout << "Конструктор с параметрами для объекта " << this << endl << endl;
}
Abiturient::Abiturient(const Abiturient &a) {
	fio = a.fio;
	spec = a.spec;
	count = a.count;
	cout << "Конструктор копирования для объекта " << this << endl << endl;
}
Abiturient::~Abiturient() {
	cout << "Деструктор для объекта " << this << endl;
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
	cout << "ФИО: " << fio << endl;
	cout << "Специальность: " << spec << endl;
	cout << "Количество балов: " << count << endl;
}