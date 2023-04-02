#include <iostream>
#include<windows.h>
#include<string>
int HASH_MAX = 100, HASH_MIN = 10;
using namespace std;

// �������� ��������� '�������'
struct human
{
    human() {
        name = "NULL";
        date = "NULL";
        address = "NULL";
    }
    string name;
    string date;
    string address;
};

// �������� ��������� '���-�������'
struct HashTable {
private:
    human* array;
public:
    HashTable() {
        array = new human[HASH_MIN];
    }
    ~HashTable() {
        delete[] array;
    }

    // ���������� ������ ����������� ��� �����
    int hashFunction(string s) {
        int sum = 0;
        for (int i = 0; s[i] != '\0'; i++) {
            sum += s[i];
        }
        return sum % HASH_MIN;
    }

    // ���������� ������ ���������� �������� � �������
    void insert(string value) {
        int hashVal = hashFunction(value);
        while (array[hashVal].name != "NULL") {
            hashVal++;
            hashVal %= HASH_MIN;
        }
        array[hashVal].name = value;
    }

    // ���������� ������ �������� �������� �� �������
    void remove(string value) {
        int hashVal = hashFunction(value);
        while (array[hashVal].name != value) {
            hashVal++;
            hashVal %= HASH_MIN;
        }
        array[hashVal].name = "NULL";
    }

    // ���������� ������ ������ �������� � �������
    int search(string value) {
        int hashVal = hashFunction(value);
        while (array[hashVal].name != value && array[hashVal].name != "NULL") {
            hashVal++;
            hashVal %= HASH_MIN;
        }
        if (array[hashVal].name == "NULL") {
            return -1;
        }
        else {
            return hashVal;
        }
    }

    // ���������� ������ ������ �������
    void print() {
        for (int i = 0; i < HASH_MIN; i++) {
            if (array[i].name != "NULL") {
                cout << i << " -> " << array[i].name << endl;
            }
            else {
                cout << i << endl;
            }
        }
    }
};

// ������������ ������ '���-�������'
int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    HashTable HT;
    HT.insert("hello");
    HT.insert("22");
    HT.insert("33");
    HT.insert("44");
    HT.insert("23");

    HT.print();  // ����� ��������� �������

    HT.remove("23");  // �������� �������� �� �������
    HT.remove("33");
    HT.print();  // ����� ��������� ������� ����� ��������

    string searchKey = "44";
    if (HT.search(searchKey) == -1) {
        cout << "������� �� ������!" << endl;
    }
    else {
        cout << "�������: " << searchKey << endl;
    }

    return 0;
}