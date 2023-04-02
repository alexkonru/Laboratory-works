#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<string.h>
#pragma warning(disable : 4996)
using namespace std;

int kol=0;

struct Node {
         string data;
         Node * next;
 
         Node(string data) {
                   this->data = data;
                   this->next = NULL;
         }
};

struct LinkedList {
         Node* head, *head2;
         LinkedList() {
                   this->head  = NULL;
         }
         ~LinkedList() {
                   clear();
		 }
         void clear(){
          	while (head != NULL)
                pop_back();
		  }
         Node* push_back(string data) {
                   Node* ptr = new Node(data);
                   ptr->next = head;
                   head = ptr;
                   return ptr;
         }
         void pop_back() {
                   if (head == NULL) return;
                   Node* ptr = head->next;
                   delete head;
                   head = ptr;
         }
         Node* getAt(int index) {
                    Node* ptr = head;
                    int n = kol-1;
                	while (n != index) {
                            if (ptr == NULL)
                                      return ptr;
                            ptr = ptr->next;
                            n--;}
                   return ptr;
         }
         Node* operator [] (int index) {
                   return getAt(index);
         }
         Node* insert(int index, string data) {
                   if (index>=kol)
                            return push_back(data);
					else{
                   Node* ptr = new Node(data);
				   Node* t = head;
				   Node* cur = t;
				   head2 = t;
				   for(int i=kol-1; i>index; i--){
					t = t->next;
					Node* cur = new Node(t->data);
					cur->next = head2;
					head2 = cur;
				   }
				   t = t->next;
				   head = ptr;
				   for (int i=index; i<kol; i++){
					cur = new Node(head2->data);
					cur->next = head;
					head = cur;
					head2 = head2->next;
				   }
				   if(index==0) ptr->next = NULL;
				   else ptr->next = t;
                   return ptr;}
         }
         void erase(int index) {
                   if (head == NULL)
                            return;
                   if (index==kol-1) {
                            pop_back();
                            return;
                   }
                   Node* t = head;
				   Node* cur = t;
				   head2 = t;
				   for(int i=kol-2; i>index; i--){
					t = t->next;
					Node* cur = new Node(t->data);
					cur->next = head2;
					head2 = cur;
				   }
				   t = t->next;
				   head = t->next;
				   for(int i=index+1;i<kol;i++){
					cur = new Node(head2->data);
					cur->next = head;
					head = cur;
					head2 = head2->next;
				   }

         }
		 void print(Node* ptr){
			if(ptr->next != NULL) print(ptr->next);
			cout<<"\t- "<<ptr->data<<endl;
		 }
};

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n=0, scount=0;
	LinkedList lst;
	string elem;
	while(n!=10)
	{
		printf("\nЧтобы открыть меню нажмите клавишу ENTER...");
		getch();
		printf("\n\t\t МЕНЮ.");
		printf("\n\t- 1.	Создание списка.");
		printf("\n\t- 2.	Добавление элемента в список.");
		printf("\n\t- 3.	Удаление элемента из списка. ");
		printf("\n\t- 4.	Печать списка.");
		printf("\n\t- 5.	Запись списка в файл.");
		printf("\n\t- 6.	Уничтожение списка.");
		printf("\n\t- 7.	Восстановление списка из файла.");
		printf("\n\t- 8.	Удалить первые k элементов.");
		printf("\n\t- 9.	Добавить элемент после элемента, начинающегося с указанного символа.");
		printf("\n\t- 10.	Выход.");
		printf("\n\n Введи номер меню: ");
		cin>>n;
		cout<<endl;
		switch (n)
		{
			case 1: {
				int k;
				cout<<"\nСколько элементов добавить в список?\n";
				cin>>k;
				kol = kol + k;
				for (int i=0;i<k;i++) {
					cout<<"\nЭлемент "<<i+1<<": ";
					cin>>elem;
					lst.push_back(elem);
					}
				cout<<"\nСписок создан!\n";
				break;}
			case 2: {
				int poz;
				cout<<"\nНа какую позицию добавить элемент?\n";
				cin>>poz;
				cout<<"\nВведи элемент: ";
				cin>>elem;
				lst.insert(poz-1, elem);
				cout<<"\nГотово!\n";
				kol = kol + 1;
				break;}
			case 3: {
				int poz;
				cout<<"\nЭлемент с каким номером удалить?\n";
				cin>>poz;
				lst.erase(poz-1);
				cout<<"\nГотово!\n";
				kol = kol - 1;	
				break;}
			case 4: {
				if (kol==0) cout<<"\nСписок пуст!\n";
				else {
					cout<<"\nСписок:\n";
					Node* ptr = lst.head;
					lst.print(ptr);}
				break;}
			case 5: {
				FILE* f;
				f = fopen("t.txt", "wb");
 				if(f==NULL) {
 					printf("\nВозникла ошибка при работе с файлом!\n");
 					getch();
					break;}
 				for(int i=0; i<kol; i++) {
 					char* c = const_cast<char*>(lst[i]->data.c_str());
 					fputs(c, f);
					fputs("\n", f);}
				fclose(f);
				printf("\nСписок был успешно записан в файл!\n");
				break;}
			case 6: {
				lst.clear();
				cout<<"\nСписок уничтожен!\n";
				scount = kol;
				kol = 0;
				break;}
			case 7: {
				FILE* f;
				f = fopen("t.txt", "rb");
 				if(f==NULL) {
 					printf("\nВозникла ошибка при работе с файлом!\n");
 					getch();
					break;}
				char s[256];
				for (int i=0; i<scount; i++){
					fgets(s, 256, f);
					s[strlen(s)-1] = '\0';
					lst.push_back(s);
				}
				kol = scount;
				fclose(f);
				printf("\nСписок был успешно восстановлен из файла!\n");
				break;}
			case 8: {
					int k;
					cout<<"\nСколько элементов с начала списка удалить?\n";
					cin>>k;
					kol = kol - k;
					for(int i=0; i<k;i++) lst.erase(1);
					cout<<"\nГотово!\n";
					break;}
			case 9: {
					char s, new_elem[256];
					bool f=false;
					cout<<"\nВведи символ: ";
					cin>>s;
					for (int i=0; i<kol; i++){
						elem = lst[i]->data;
                   		if (elem[0] == s) {
                   			cout<<"\nЭлемент найден!\n";
                   			cout<<"\nНовый элемент: ";
                   			cin>>new_elem;
						    lst.insert(i+1, new_elem);
						    f=true;
							}
						i++;	
                   		}
                   	if (f==false) cout<<"\nНет элемента, начинающегося с этого символа!\n";
                   	else { cout<<"\nГотово!\n";
                   	kol = kol +1;}
					break;}
			case 10: {
					printf("\n\tДля завершения работы программы нажмите клавишу Enter...");
					break;}
			default: printf("\n\tОШИБКА! Нет такого номера меню.\n\n");
		}
	}
	return(0);
}