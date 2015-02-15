// mehtayn.com
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
struct node *head;
void insertAtFront(int key)//basa ekleme
{
	if(head==NULL)// head yoksa
	{
		head=new node();
		head->data=key;
		head->next=head;

		
	}
	else
	{
		struct node *last=head;
		while(last->next!=head) 
			last=last->next;
		struct node *temp=new node();
		temp->data=key;
		temp->next=head;
		last->next=temp;
		head=temp;
		

	}
}
void insertAtEnd(int key)
{
	if(head==NULL)
	{
		head=new node();
		head->data=key;
		head->next=head;
	}
	else
	{
		struct node *temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=new node();
		temp->next->data=key;
		temp->next->next=head;
	}
}
void print()
{
	struct node *temp=head;

	while(temp->next!=head)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);
}
node *remove(int key)
{
	struct node *temp=head;
	if(head->data==key)
	{
		head=head->next;
		free(temp);
	}
	else
	{
		while(temp->next->data!=key)
			temp=temp->next;
		struct node *temp2=temp->next;
		temp->next=temp->next->next;
		free(temp2);
	}
	return head;
}
int count()
{
	struct node *temp2=head;
	if(head==NULL)
	{
		printf("Liste Boş");
		return 0;
	}

	int counter=1;
	while(temp2->next!=head)
	{
		counter++;
		temp2=temp2->next;
	}
	return counter;
}

main()
{
	insertAtFront(12);
	print();
	printf("\n************\n");
	insertAtFront(3);
	insertAtEnd(1);
	print();
	printf("\n************\n");
	insertAtFront(5);
	insertAtEnd(7);
	print();
	printf("\n************\n");
	remove(3);
	print();
	printf("Liste %d eleman vardır", count());
	getch();
}

