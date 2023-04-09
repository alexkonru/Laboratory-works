#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <windows.h>
using namespace std;

string f[5] = { "�������", "������", "�������", "��������", "������" };
string i[5] = { "�������", "������", "�����", "��������", "������" };
string o[5] = { "������������", "�������������", "���������", "����������", "����������" };
string d[5] = { "09.07.97", "22.09.85", "12.02.99", "02.03.88", "25.05.02" };
string g[5] = { "����� �����������, ����� ������������, 39", "����� ���������� �����, ����� 1905 ����, 87", "����� ��������, ���. �������������, 99", "����� �������, ���. �����������, 53", "����� �������������, ��. ������������, 46" };
int n = 0;
char date[255];
FILE* file;

struct Human {
    char fio[255];
    char dateofbirth[255];
    char address[255];
};

struct Node {
    Human human;
    Node* next;
};

struct LinkedList {
    Node* last, * cur, * head;
};

LinkedList* m = new LinkedList;

void ChangeValue(char* c, string r) {
    for (int k = 0; k < r.length(); k++) {
        c[k] = r[k];
    }
    c[r.length()] = '\0';
}

int RandomNuberSensor() {
    return rand() % 5;
}

int GetPosibleKey() {
    double key = 0;
    for (int k = 0; k < 9; k += 3) {
        string s = "";
        s += date[k];
        s += date[k + 1];
        key += stoi(s);
    }
    key *= 0.75;
    key -= (int)key;
    return (int)(n * key);
}

void CreateHash() {
    cout << "������� ���������� ���������: ";
    cin >> n;
    LinkedList* t = new LinkedList[n]{};
    int collision = 0;
    for (int k = 0; k < n; k++) {
        ChangeValue(date, d[RandomNuberSensor()]);
        int l = GetPosibleKey();
        bool occupied = t[l].head != NULL;
        t[l].cur = t[l].head;
        if (occupied) {
            while (t[l].cur->next != NULL) {
                t[l].cur = t[l].cur->next;
            }
        }
        Node* p = new Node;
        ChangeValue(p->human.fio, f[RandomNuberSensor()] + ' ' + i[RandomNuberSensor()] + ' ' + o[RandomNuberSensor()]);
        ChangeValue(p->human.dateofbirth, date);
        ChangeValue(p->human.address, g[RandomNuberSensor()]);
        if (occupied) {
            collision++;
            t[l].cur->next = p;
            t[l].cur->next->next = NULL;
        }
        else {
            t[l].head = p;
            t[l].head->next = NULL;
        }
    }
    delete[] m;
    m = t;
    cout << "���-������� �������! " << "���������� ��������: " << collision << '\n';
}

void ShowHash() {
    if (n) {
        for (int k = 0; k < n; k++) {
            if (m[k].head != NULL) {
                cout << "���� " << k << ":\n";
                m[k].cur = m[k].head;
                while (m[k].cur != NULL) {
                    cout << m[k].cur->human.fio << ' ' << m[k].cur->human.dateofbirth << ' ' << m[k].cur->human.address << '\n';
                    m[k].cur = m[k].cur->next;
                }
            }
        }
        cout << "-------------------------------\n";
    }
    else {
        cout << "���-������� �����!\n";
    }
}

void DeleteFromHash() {
    if (n) {
        cout << "������� ����: ";
        cin.getline(date, 255);
        cin >> date;
        for (int k = 0; k < n; k++) {
            m[k].cur = m[k].head;
            while (m[k].cur != NULL) {
                if (!strcmp(m[k].cur->human.dateofbirth, date)) {
                    ChangeValue(m[k].cur->human.fio, "NULL");
                    ChangeValue(m[k].cur->human.dateofbirth, "NULL");
                    ChangeValue(m[k].cur->human.address, "NULL");
                }
                m[k].cur = m[k].cur->next;
            }
        }
    }
    else {
        cout << "���-������� �����!\n";
    }
}

void FindIntoHash() {
    if (n) {
        cin.get();
        cout << "������� ����: ";
        cin.getline(date, 255);
        int l = GetPosibleKey();
        for (int k = 0; k < n; k++) {
            m[l].cur = m[l].head;
            while (m[l].cur != NULL) {
                if (!strcmp(m[l].cur->human.dateofbirth, date)) {
                    cout << l + 1 << '\n';
                    return;
                }
                m[l].cur = m[l].cur->next;
            }
            l = (l + 1) % n;
        }
        cout << "-1\n";
    }
    else {
        cout << "���-������� �����, �������� �� ��������!\n";
    }
}

void AddElement() {
    int l;
    cout << "������� ����� ������ ��������: ";
    cin >> l;
    Node* q = new Node;///��������� ����� �������
    ChangeValue(q->human.fio, f[RandomNuberSensor()] + ' ' + i[RandomNuberSensor()] + ' ' + o[RandomNuberSensor()]);//
    ChangeValue(q->human.dateofbirth, d[RandomNuberSensor()]);//
    ChangeValue(q->human.address, g[RandomNuberSensor()]);///
    if (l > n) {//���� ����� ������� ������ ���������� � ��� �������������� �����, �� ����� �������� ������ �������
        LinkedList* t = new LinkedList[l]{};//������ ����� ������
        for (int k = 0; k < n; k++) {
            t[k] = m[k];//������� �������� �� �������
        }
        delete[] m;
        m = t;
        n = l;
        q->next = NULL;//������ ��������� �� NULL, ��� ��� ������ ������� ��� ������ ������
        m[l - 1].head = q;//����� ����� ������� � ������������ ������, � ����� ������
    }
    else if (m[l - 1].head != NULL && strcmp(m[l - 1].head->human.fio, "NULL")) {//���� ������ ������� ��� ������ ������ �� NULL � �� �� ������� ��� �������� ("NULL") 
        m[l - 1].cur = m[l - 1].head;//������������� ������� �� ������
        while (m[l - 1].cur->next != NULL && strcmp(m[l - 1].cur->next->human.fio, "NULL")) {//���� ��������� �� NULL ��� "NULL"
            m[l - 1].cur = m[l - 1].cur->next;//������� ���������
        }
        if (m[l - 1].cur->next == NULL) {//���� ��������� NULL
            q->next = NULL;//���������� ������ �� NULL, ��� ��� ����� ������
        }
        else {//���� "NULL"
            q->next = m[l - 1].cur->next->next;//���������� �� ���������->��������� �������
        }
        m[l - 1].cur->next = q;//������ �������� ���������� ��������
    }
    else {//���� ����� NULL ��� "NULL"
        if (m[l - 1].head == NULL) {
            q->next = NULL;//���������� �� NULL, ��� ��� ����� ������
            m[l - 1].head = q;//����� ������ ��������
        }
        else {//���� "NULL"
            q->next = m[l - 1].head->next;//����� �������� ����������
            m[l - 1].head = q;//����� �������� ������
        }
    }
}

void RestoreHash() {
    if ((file = fopen("Hash.txt", "rb")) == NULL) {
        cout << "������ ������ �����\n";
    }
    else if (!feof(file)) {
        fread(&n, sizeof(n), 1, file);
        LinkedList* t = new LinkedList[n]{};
        char c;
        fread(&c, sizeof(c), 1, file);
        for (int k = 0; k < n; k++) {
            fread(&c, sizeof(c), 1, file);
            if (c == ' ') {
                Node* q = new Node;
                fread(&q->human, sizeof(Human), 1, file);
                t[k].cur = t[k].head = q;
                t[k].cur->next = NULL;
                fread(&c, sizeof(c), 1, file);
                while (c != 'h') {
                    Node* q = new Node;
                    fread(&q->human, sizeof(Human), 1, file);
                    t[k].cur->next = q;
                    t[k].cur = t[k].cur->next;
                    t[k].cur->next = NULL;
                    fread(&c, sizeof(c), 1, file);
                }
            }
        }
        delete[] m;
        m = t;
        fclose(file);
    }
    else {
        cout << "���� ����, �������� �� ��������!\n";
        fclose(file);
    }
}

void WriteHash() {
    if (n) {
        file = fopen("t.txt", "wb");
        fwrite(&n, sizeof(n), 1, file);
        char space = ' ';
        char newline = 'h';
        fwrite(&newline, sizeof(newline), 1, file);
        for (int k = 0; k < n; k++) {
            m[k].cur = m[k].head;
            while (m[k].cur != NULL) {
                fwrite(&space, sizeof(space), 1, file);
                fwrite(&m[k].cur->human, sizeof(Human), 1, file);
                m[k].cur = m[k].cur->next;
            }
            fwrite(&newline, sizeof(newline), 1, file);
        }
        fclose(file);
    }
    else {
        cout << "���-������� �����, �������� �� ��������!\n";
    }
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");
    SetConsoleOutputCP(866);
    SetConsoleCP(866);
    int n;
    bool f = true;
    while (f) {
        cout << "����\n";
        cout << "1. ������� ���-�������\n";
        cout << "2. �������� ���-�������\n";
        cout << "3. ������� �� ���-������� ������� � ��������� ����� ��������\n";
        cout << "4. ������������ ���-������� �� �����\n";
        cout << "5. ����� ����� �������� � ���-������� �� ���� ��������\n";
        cout << "6. �������� ���-������� � ����\n";
        cout << "7. �������� ������� � ���-�������\n";
        cout << "8. ����� �� ���������\n";
        cin >> n;
        system("cls");
        switch (n) {
        case(1):
            CreateHash();
            break;
        case(2):
            ShowHash();
            break;
        case(3):
            DeleteFromHash();
            break;
        case(4):
            RestoreHash();
            break;
        case(5):
            FindIntoHash();
            break;
        case(6):
            WriteHash();
            break;
        case(7):
            AddElement();
            break;
        case(8):
            f = false;;
            break;
        default:
            cout << "Error!";
            break;
        }
    }
    return 0;
}