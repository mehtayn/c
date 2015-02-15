// mehtayn.com
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define N 6
int queue[N]={0};
int rear=0,front=0;
void insert(void);//ekleme
void del(void);//silme
void disp(void);//gösterme
int main()
{
	int user=0;
	while(user!=4)
	{
		printf("1-INSERT\n2-DELETE\n3-DISPLAY\n4-EXIT\n");
		scanf("%d",&user);
		switch(user)
		{
			case 1:
				insert();
				break;
			case 2:
				del();
				break;
			case 3:
				disp();
				break;
			case 4:
				exit(0);
		}
	}
	getch();
}
void insert(void)//ekleme
{
	int t;
	if(rear<N)
	{
		printf("ENTER A VALUE:\n");
		scanf("%d",&t);
		queue[rear]=t;
		rear++;
		system("cls");
		printf("New Element Added\n");
	}
	else
	{
		system("cls");
		printf("Q OVERFLOW!!!!!\n");
	}
}
void del(void)//silme
{
	int i;
	system("cls");
	printf("%d gets deleted\n",queue[front]);
	queue[front]=0;
	front++;
}
void disp(void)//gösterme
{
	system("cls");
	printf("Queue Element List\n");
	for (int i = front; i < rear; i++)
	{
		printf("%d\n",queue[i]);
	}

}
