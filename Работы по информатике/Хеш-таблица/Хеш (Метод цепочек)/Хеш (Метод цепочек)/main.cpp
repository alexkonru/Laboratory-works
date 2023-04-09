#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <windows.h>
using namespace std;

string f[5] = { "Романов", "Петров", "Назаров", "Алексеев", "Сидоов" };
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
    cout << "Введите количество элементов: ";
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
    cout << "Хеш-таблица создана! " << "Количество коллизий: " << collision << '\n';
}

void ShowHash() {
    if (n) {
        for (int k = 0; k < n; k++) {
            if (m[k].head != NULL) {
                cout << "Ключ " << k << ":\n";
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
        cout << "Хеш-таблица пуста!\n";
    }
}

void DeleteFromHash() {
    if (n) {
        cout << "Введите дату: ";
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
        cout << "Хеш-таблица пуста, операция не возможна!\n";
    }
}

void AddElement() {
    int l;
    cout << "Введите номер нового элемента: ";
    cin >> l;
    Node* q = new Node;///генерирую новый элемент
    ChangeValue(q->human.fio, f[RandomNuberSensor()] + ' ' + i[RandomNuberSensor()] + ' ' + o[RandomNuberSensor()]);//
    ChangeValue(q->human.dateofbirth, d[RandomNuberSensor()]);//
    ChangeValue(q->human.address, g[RandomNuberSensor()]);///
    if (l > n) {//если новый элемент должен находиться в ещё несуществующем ключе, то нужно изменить размер массива
        LinkedList* t = new LinkedList[l]{};//создаём новый массив
        for (int k = 0; k < n; k++) {
            t[k] = m[k];//передаём значения из старого
        }
        delete[] m;
        m = t;
        n = l;
        q->next = NULL;//должен указывать на NULL, так как первый элемент под данным ключом
        m[l - 1].head = q;//задаём новый элемент в получивщийся массив, в новую ячейку
    }
    else if (m[l - 1].head != NULL && strcmp(m[l - 1].head->human.fio, "NULL")) {//если первый элемент под нужным ключом не NULL и не не помечен как удалённый ("NULL") 
        m[l - 1].cur = m[l - 1].head;//устанавливаем текущий на голову
        while (m[l - 1].cur->next != NULL && strcmp(m[l - 1].cur->next->human.fio, "NULL")) {//пока следующий не NULL или "NULL"
            m[l - 1].cur = m[l - 1].cur->next;//получаю следующий
        }
        if (m[l - 1].cur->next == NULL) {//если слудующий NULL
            q->next = NULL;//обращаться должен на NULL, так как конец списка
        }
        else {//если "NULL"
            q->next = m[l - 1].cur->next->next;//обращается на следующий->следующий элемент
        }
        m[l - 1].cur->next = q;//меняем значение следующего элемента
    }
    else {//если сразу NULL или "NULL"
        if (m[l - 1].head == NULL) {
            q->next = NULL;//обращается на NULL, так как конец списка
            m[l - 1].head = q;//задаём голове значение
        }
        else {//если "NULL"
            q->next = m[l - 1].head->next;//задаём значение слудующего
            m[l - 1].head = q;//задаём значение голове
        }
    }
}

void RestoreHash() {
    if ((file = fopen("Hash.txt", "rb")) == NULL) {
        cout << "Ошибка чтения файла\n";
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
        cout << "Файл пуст, операция не возможна!\n";
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