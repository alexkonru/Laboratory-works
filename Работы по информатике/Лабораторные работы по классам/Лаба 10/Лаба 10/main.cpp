#include <iostream>
#include "Pair.h"
#include <string>
#include "file_work.h"
using namespace std;

int main() {
	Pair p, p1, p2;
	int k, c;
	char file_name[30];
	do
	{
		cout << "\n1. Make file";
		cout << "\n2. Print file";
		cout << "\n3. Delete record from file";
		cout << "\n4. Add record to file";
		cout << "\n5. Change record in file";
		cout << "\n0. Exit\n";
		cin >> c;
		switch (c)
		{
		case 1: cout << "File name?\n"; cin >> file_name;
			k = make_file(file_name);
			if (k < 0)cout << "Can't make file\n";
			break;
		case 2: cout << "File name?\n"; cin >> file_name;
			k = print_file(file_name);
			if (k == 0)cout << "Empty file\n";
			if (k < 0)cout << "Can't read file\n";
		case 3: cout << "File name?\n"; cin >> file_name;
			int nom; cout << "Nom?"; cin >> nom;
			k = del_file(file_name, nom);
			if (k < 0)cout << "Can't read file";
			break;
		case 4: cout << "File name?\n";
			cin >> file_name;
			cout << "Nom?"; cin >> nom;
			cout << "New pair: ";
			cin >> p1;
			k = add_file(file_name, nom, p1);
			if (k < 0) cout << "Can't read file";
			if (k == 0) k = add_end(file_name, p1);
			break;
		case 5: cout << "File name?\n";
			cin >> file_name;
			cout << "Nom?"; cin >> nom;
			cout << "New pair: ";
			cin >> p2;
			k = change_file(file_name, nom, p2);
			if (k < 0) cout << "\nCan't read file";
			if (k == 0) cout << "\nNot such record";
			break;
		default:
			break;
		}
	} while (c != 0);
}