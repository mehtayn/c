//www.mehtayn.com

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
node *addhead(node *head) //basa ekle
{
	node *temp=new node();
	temp->data=8;
	temp->next=head;
	head=temp;
	return head;
}
node *addlast(node *head) // sona ekle
{
	node *temp=new node();
	temp-> data=7;
	temp->next=NULL;
	node *temp2=head;
	while(temp2->next!=NULL)
		temp2=temp2->next;
	temp2->next=temp;
	return head;
}
void prnt(node *head) // listeyi göster
{
	if(head==NULL)
	{
		printf("Liste Boş\n");
		return ;
	}
	node *temp2=head;
	while(temp2 != NULL)
	{
		printf("%d\n",temp2->data);
		temp2=temp2->next;
	}
}
int count (node *head) //listeyi say
{
	if(head==NULL)
	{
		printf("Liste Boş\n");
		return 0;
	}
	node *temp2 =head;
	int counter = 0;
	while(temp2 != NULL)
	{
		counter++;
		temp2=temp2->next;
	}
	return counter;
}
void print_rec(node *head) //listeyi göster2
{
	if(head==NULL) return;
	else
	{
		printf("%d\n",head->data);
		print_rec(head->next);
	}
}
node *remove(struct node *head,int key)
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
void Reverse(struct node *p)
{
	if(p==NULL) return ;
	Reverse(p->next);
	printf("%d\n",p->data);
}
main()
{
node *head;
	head =new node();
	head->data=1;
	head->next=NULL;
	head->next=new node();
	head->next->data=3;
	head->next->next=NULL;
	printf("ilk liste\n");
	prnt(head);
	printf("Eleman sayisi %d\n",count(head));
	head=addhead(head);
	head=addlast(head);
	head=addlast(head);
	prnt(head);
	printf("Eleman sayisi %d\n",count(head));
	remove(head,3);
	remove(head,1);
	remove(head,7);				
	print_rec(head);
	printf("***************************\n");
	Reverse(head);
	getch();
}
