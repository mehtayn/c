// mehtayn.com
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
struct node
{
	int data;
	node *next;
	node *previous;
};
node *head;
void insertAtFirst(int key)//basa ekleme
{
	if(head==NULL)// head yoksa
	{
		head=new node();
		head->data=key;
		head->previous=NULL;
		head->next=NULL;
	}
	else
	{
		struct node *temp;
		temp =new node();
		temp->data=key;
		temp->previous=NULL;
		temp->next=head;
		head->previous=temp;
		head=temp;
	}
}
void insertAtEnd(int key)//sona eklemek
{
	if(head==NULL)//head yoksa
	{
		head=new node();
		head->data=key;
		head->previous=NULL;
		head->next=NULL;
	}
	else
	{
		struct node *temp=head;
		while (temp->next!=NULL)
			temp=temp->next;
		struct node *temp2=new node();
		temp2->data=key;
		temp->next=temp2;
		temp2->previous=temp;
		temp2->next=NULL;
	}
}
void remove (int key)// istenılen data yı sil
{
	struct node *temp=head;
	if(head->data==key)
	{
		head=head->next;
		head->previous=NULL;
		free(temp);
	}
	else
	{
		while(temp->data!=key)
		{
			temp=temp->next;
		
		}
			temp->previous->next=temp->next;
			//temp->next->previous=temp->previous;
			free(temp);
	}
}
void print()// listeyi göster
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}
int count()
{
	struct node *temp2=head;
	if(head==NULL) printf("Liste Boş");
	int counter=0;
	while(temp2!=NULL) 
	{
		counter++;
		temp2=temp2->next;
	}
	return counter;
}
main()
{
	insertAtFirst(4);
	print();
	printf("*********\n");
	insertAtFirst(8);
	insertAtEnd(12);
	insertAtEnd(11);
	print();
	printf("*********\n");
	remove(12);
	print();
	printf("*********\n");
	printf("Listedeki eleman sayisi %d",count());
	getch();
}
