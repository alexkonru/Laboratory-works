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
         Node* prev, * next;
 
         Node(string data) {
                   this->data = data;
                   this->prev = this->next = NULL;
         }
};

struct LinkedList {
         Node* head, * tail;

         LinkedList() {
                   this->head = this->tail = NULL;
         }
         
         ~LinkedList() {
                   clear();
         }
         
          void clear(){
          	while (head != NULL)
                pop_front();
		  }
          
          Node* push_front(string data) {
                   Node* ptr = new Node(data);
                   
                   ptr->next = head;
                   if (head != NULL)
                            head->prev = ptr;
                   if (tail == NULL)
                            tail = ptr;
                   head = ptr;
 
                   return ptr;
         }
 
         Node* push_back(string data) {
                   Node* ptr = new Node(data);
 
                   ptr->prev = tail;
                   if (tail != NULL)
                            tail->next = ptr;
                   if (head == NULL)
                            head = ptr;
                   tail = ptr;
 
                   return ptr;
         }
         
          void pop_front() {
                   if (head == NULL) return;
                   
                   Node* ptr = head->next;
                   if (ptr != NULL)
                            ptr->prev = NULL;
                   else
                            tail = NULL;
 
                   delete head;
                   head = ptr;
         }
 
         void pop_back() {
                   if (tail == NULL) return;
 
                   Node* ptr = tail->prev;
                   if (ptr != NULL)
                            ptr->next = NULL;
                   else
                            head = NULL;
 
                   delete tail;
                   tail = ptr;
         }
         
          Node* getAt(int index) {
                   Node* ptr = head;
                   int n = 0;
                   
                   	while (n != index) {
                            if (ptr == NULL)
                                      return ptr;
                            ptr = ptr->next;
                            n++;}
                   return ptr;
         }
 
         Node* operator [] (int index) {
                   return getAt(index);
         }
         
          Node* insert(int index, string data) {
                   Node* right = getAt(index);
                   if (right == NULL)
                            return push_back(data);
 
                   Node* left = right->prev;
                   if (left == NULL)
                            return push_front(data);
 
                   Node* ptr = new Node(data);
                   
                   ptr->prev = left;
                   ptr->next = right;
                   left->next = ptr;
                   right->prev = ptr;
 
                   return ptr;
         }
         
          void erase(int index) {
                   Node* ptr = getAt(index);
                   if (ptr == NULL)
                            return;
 
                   if (ptr->prev == NULL) {
                            pop_front();
                            return;
                   }
 
                   if (ptr->next == NULL) {
                            pop_back();
                            return;
                   }
 
                   Node* left = ptr->prev;
                   Node* right = ptr->next;
                   left->next = right;
                   right->prev = left;
 
                   delete ptr;
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
		printf("\n����� ������� ���� ������� ������� ENTER...");
		getch();
		printf("\n\t\t ����.");
		printf("\n\t- 1.	�������� ������.");
		printf("\n\t- 2.	���������� �������� � ������.");
		printf("\n\t- 3.	�������� �������� �� ������. ");
		printf("\n\t- 4.	������ ������.");
		printf("\n\t- 5.	������ ������ � ����.");
		printf("\n\t- 6.	����������� ������.");
		printf("\n\t- 7.	�������������� ������ �� �����.");
		printf("\n\t- 8.	������� ������ k ���������.");
		printf("\n\t- 9.	�������� ������� ����� ��������, ������������� � ���������� �������.");
		printf("\n\t- 10.	�����.");
		printf("\n\n ����� ����� ����: ");
		cin>>n;
		cout<<endl;
		switch (n)
		{
			case 1: {
				int k;
				cout<<"\n������� ��������� �������� � ������?\n";
				cin>>k;
				kol = kol + k;
				for (int i=0;i<k;i++) {
					cout<<"\n������� "<<i+1<<": ";
					cin>>elem;
					lst.push_back(elem);
					}
				cout<<"\n������ ������!\n";
				break;}
			case 2: {
				int poz;
				cout<<"\n�� ����� ������� �������� �������?\n";
				cin>>poz;
				cout<<"\n����� �������: ";
				cin>>elem;
				lst.insert(poz-1, elem);
				cout<<"\n������!\n";
				kol = kol + 1;
				break;}
			case 3: {
				int poz;
				cout<<"\n������� � ����� ������� �������?\n";
				cin>>poz;
				lst.erase(poz-1);
				cout<<"\n������!\n";
				kol = kol - 1;	
				break;}
			case 4: {
				if (kol==0) cout<<"\n������ ����!\n";
				else {
					cout<<"\n������:\n";
					for (int i=0; i<kol; i++)
               			cout<<"\t- "<<lst[i]->data<<endl;}
				break;}
			case 5: {
				FILE* f;
				f = fopen("t.txt", "wb");
 				if(f==NULL) {
 					printf("\n�������� ������ ��� ������ � ������!\n");
 					getch();
					break;}
 				for(int i=0; i<kol; i++) {
 					char* c = const_cast<char*>(lst[i]->data.c_str());
 					fputs(c, f);
					fputs("\n", f);}
				fclose(f);
				printf("\n������ ��� ������� ������� � ����!\n");
				break;}
			case 6: {
				lst.clear();
				cout<<"\n������ ���������!\n";
				scount = kol;
				kol = 0;
				break;}
			case 7: {
				FILE* f;
				f = fopen("t.txt", "rb");
 				if(f==NULL) {
 					printf("\n�������� ������ ��� ������ � ������!\n");
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
				printf("\n������ ��� ������� ������������ �� �����!\n");
				break;}
			case 8: {
					int k;
					cout<<"\n������� ��������� � ������ ������ �������?\n";
					cin>>k;
					kol = kol - k;
					for(int i=0; i<k;i++) lst.pop_front();
					cout<<"\n������!\n";
					break;}
			case 9: {
					char s, new_elem[256];
					int i=0;
					bool f=false;
					cout<<"\n����� ������: ";
					cin>>s;
					for (int i=0; i<kol; i++){
						elem = lst[i]->data;
                   		if (elem[0] == s) {
                   			cout<<"\n������� ������!\n";
                   			cout<<"\n����� �������: ";
                   			cin>>new_elem;
						    lst.insert(i+1, new_elem);
						    f=true;
							}
						i++;	
                   		}
                   	if (f==false) cout<<"\n��� ��������, ������������� � ����� �������!\n";
                   	else { cout<<"\n������!\n";
                   	kol = kol +1;}
					break;}
			case 10: {
					printf("\n\t��� ���������� ������ ��������� ������� ������� Enter...");
					break;}
			default: printf("\n\t������! ��� ������ ������ ����.\n\n");
		}
	}
	return(0);
}
