#pragma once
#include <iostream>
#include <string>
using namespace std;
class Abiturient {
	string fio;
	string spec;
	int count;
public:
	Abiturient();
	Abiturient(string, string, int);
	Abiturient(const Abiturient&);
	~Abiturient();
	string get_fio();
	void set_fio(string);
	string get_spec();
	void set_spec(string);
	int get_count();
	void set_count(int);
	void show();
};