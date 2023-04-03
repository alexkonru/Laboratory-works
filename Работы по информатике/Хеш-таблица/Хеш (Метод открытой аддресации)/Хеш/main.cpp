#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <windows.h>
using namespace std;

string f[5] = {"Романов", "Петров", "Назаров", "Алексеев", "Сидоов"};
string i[5] = { "Дмитрий", "Матвей", "Денис", "Владимир", "Максим" };
string o[5] = { "Владимирович", "Владиславович", "Андреевич", "Михайлович", "Николаевич" };
string d[5] = { "09.07.97", "22.09.85", "12.02.99", "02.03.88", "25.05.02" };
string g[5] = { "город Красногорск, въезд Бухарестская, 39", "город Павловский Посад, спуск 1905 года, 87", "город Подольск, наб. Будапештсткая, 99", "город Пушкино, пер. Космонавтов, 53", "город Солнечногорск, ул. Бухарестская, 46" };
int n = 0;
char date[255];
FILE* file;

struct Human {
    char fio[255];
    char dateofbirth[255];
    char address[255];
};

Human* m = new Human;

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
    cout << "Введите количество элементов: ";
    cin >> n;
    Human* t = new Human[n]{};
    int collision = 0;
    for (int k = 0; k < n; k++) {
        ChangeValue(date, d[RandomNuberSensor()]);
        int l = GetPosibleKey();
        if (t[l].fio[0] != NULL) {
            collision++;
        }
        while (t[l].fio[0] != NULL) {
            l = (l + 1) % n;
        }
        ChangeValue(t[l].fio, f[RandomNuberSensor()] + ' ' + i[RandomNuberSensor()] + ' ' + o[RandomNuberSensor()]);
        ChangeValue(t[l].dateofbirth, date);
        ChangeValue(t[l].address, g[RandomNuberSensor()]);
    }
    delete[] m;
    m = t;
    cout << "Хеш-таблица создана! " << "Количество коллизий: " << collision << '\n';
}

void ShowHash() {
    if (n) {
        for (int k = 0; k < n; k++) {
            cout << m[k].fio << ' ' << m[k].dateofbirth << ' ' << m[k].address << '\n';
        }
        cout << "-------------------------------\n";
    }
    else {
        cout << "Хеш-таблица пуста!\n";
    }
}

void DeleteFromHash() {
    if (n) {
        cout << "Введите дату: ";
        cin.getline(date, 255);
        cin >> date;
        for (int k = 0; k < n; k++) {
            if (!strcmp(m[k].dateofbirth, date)) {
                ChangeValue(m[k].fio, "NULL");
                ChangeValue(m[k].dateofbirth, "NULL");
                ChangeValue(m[k].address, "NULL");
            }
        }
    }
    else {
        cout << "Хеш-таблица пуста!\n";
    }
}

void FindIntoHash() {
    if (n) {
        cin.get();
        cout << "Введите дату: ";
        cin.getline(date, 255);
        int l = GetPosibleKey();
        for (int k = 0; k < n; k++) {
            if (!strcmp(m[l].dateofbirth, date)) {
                cout << l + 1 << '\n';
                return;
            }
            l = (l + 1) % n;
        }
        cout << "-1\n";
    }
    else {
        cout << "Хеш-таблица пуста, операция не возможна!\n";
    }
}

void AddElement() {
    int l;
    cout << "Введите номер нового элемента: ";
    cin >> l;
    if (l > n || strcmp(m[l-1].dateofbirth, "NULL")) {
        Human* t = new Human[n >= l ? n + 1 : l];
        for (int k = 0; k < l - 1; k++) {
            t[k] = m[k];
        }
        for (int k = l; k < n; k++) {
            t[k] = m[k - 1];
        }
        for (int k = n; k < l; k++) {
            ChangeValue(t[k].fio, "NULL");
            ChangeValue(t[k].dateofbirth, "NULL");
            ChangeValue(t[k].address, "NULL");
        }
        n = n >= l ? n + 1 : l;
        delete[] m;
        m = t;
    }
    ChangeValue(m[l - 1].fio, f[RandomNuberSensor()] + ' ' + i[RandomNuberSensor()] + ' ' + o[RandomNuberSensor()]);
    ChangeValue(m[l - 1].dateofbirth, d[RandomNuberSensor()]);
    ChangeValue(m[l - 1].address, g[RandomNuberSensor()]);

}

void RestoreHash() {
    if ((file = fopen("t.txt", "rb")) == NULL) {
        cout << "Ошибка чтения файла\n";
    }
    else if (!feof(file)) {
        fread(&n, sizeof(n), 1, file);
        Human* t = new Human[n];
        for (int k = 0; k < n; k++) {
            fread(&t[k], sizeof(Human), 1, file);
        }
        delete[] m;
        m = t;
        fclose(file);
    }
    else {
        cout << "Файл пуст, операция не возможна!\n";
        fclose(file);
    }
}

void WriteHash() {
    if (n) {
        file = fopen("t.txt", "wb");
        fwrite(&n, sizeof(n), 1, file);
        for (int k = 0; k < n; k++) {
            fwrite(&m[k], sizeof(Human), 1, file);
        }
        fclose(file);
    }
    else {
        cout << "Хеш-таблица пуста, операция не возможна!\n";
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
        cout << "МЕНЮ\n";
        cout << "1. Создать Хеш-таблицу\n";
        cout << "2. Показать Хеш-таблицу\n";
        cout << "3. Удалить из Хеш-таблицы элемент с выбранной датой рождения\n";
        cout << "4. Восстановить Хеш-таблицу из файла\n";
        cout << "5. Найти номер элемента в Хеш-таблице по дате рождения\n";
        cout << "6. Записать Хеш-таблицу в файл\n";
        cout << "7. Добавить элемент в Хеш-таблицу\n";
        cout << "8. Выход из программы\n";
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