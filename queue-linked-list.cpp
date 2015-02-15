// mehtayn.com
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define EMPTY 0
#define FULL 10
using namespace std;
struct node
{
	int d;
	struct node *next;
};
typedef struct node node;
struct queue 
{
	int cnt;
	node *front;
	node *rear;
};
typedef struct queue queue  ;
bool isempty(queue  *q)
{
	return (q->cnt==EMPTY);
}
bool isfull( queue  *q)
{
	return (q->cnt==FULL);
}
int front(queue  *q )
{
	return (q->front->d);
}
void initialize(queue  *q)//kuyrugu sıfırla
{
	q->cnt=0;
	q->front=NULL;
	q->rear=NULL;
}
void enqueue(int x,queue  *q)//kuyruga ekleme
{
	node *p;
	p=new node();
	p->d=x;
	p->next=NULL;
	if(!isempty(q))
	{
		q->rear->next=p;
		q->rear	=p;
	}
	else
		q->front=q->rear=p;
	q->cnt++;
}
int dequeue(queue  *q)//kuyrukta cıkarma
{
	int x;
	node *p;
	x=q->front->d;
	p=q->front;
	q->front =q->front->next;
	q->cnt--;
	delete(p);
	return x;
}
void prnt(queue  *q)//kuyrugu göster
{
	node *p;
	for(p=q->front;p!=NULL;p=p->next)
		printf("%d\n",p->d);
	printf("\n");
}
int main()
{
	queue  my_q;
	int op;
	int x;
	initialize(&my_q);
	do
	{
		printf("İlk giren ilk çıkar!\n");
		printf("\n 1-ENQUEUE \n 2-DEQUEUE \n 3-FRONT \n 4-IS FULL \n 5-IS EMPTY \n 6-PRINT \n 7-EXİT\n");
		scanf("%d",&op);
		switch (op)
		{
		case 1:	printf("Queue value:"); scanf("%d",&x);
				enqueue(x,&my_q);
				system("cls");
				printf("New Element Added\n\n");
				break;
		case 2: dequeue(&my_q);
				system("cls");
				printf("One element deleted\n\n");
				break;
		case 3: system("cls");
				printf("Front :%d\n",front(&my_q));
				break;
		case 4: system("cls");
				if(!isfull(&my_q)==true)
					printf("Queue is FULL\n");
				else
					printf("Queue is NOT FULL\n\n");
				break;
		case 5: system("cls");
			if(!isempty(&my_q)==true)
					printf("Queue is EMPTY\n");
				else
					printf("Queue is NOT EMPTY\n\n");
				break;
		case 6: system("cls");
				printf("Queue Element List\n");
				prnt(&my_q);
				break;
		case 7: exit(0);
		default: break;
			break;
		}
	}while(op!=7);
	getch();


}
