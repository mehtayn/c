#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct kisiler{
 char name[25];
 int roll;
 int age;
 struct kisiler *next;
};

typedef struct kisiler kisi;
kisi *head,*new_;

void ListOlus(){
 int n,i;
 printf("Kisi sayisi");
 scanf("%d",&n);
 for(i=0;i<n;i++){
  if(i==0){
   new_=(kisi *)malloc(sizeof(kisi));
   head=new_;
  }else{
   new_->next=(kisi *)malloc(sizeof(kisi));
   new_=new_->next;
  }
  printf("Roll name age:\n");
scanf("%d%s%d",&new_->roll,new_->name,&new_->age);
  
 }
 new_->next=NULL; 
}

void ListGoster(){
 kisi *p;
 p=head;
 while(p!=NULL){
  printf("%d-",p->roll);
  printf("%s ",p->name);
  printf("%d\n",p->age);
  p=p->next;
 }
}

void ListEkle(){
 int ara;
 kisi *p,*q,*new_;
 p=head;
 new_=(kisi *)malloc(sizeof(kisi));
 printf("\nhangi roll:");scanf("%d",&ara);
 printf("**********************\n");
  printf("Roll name age:\n");
 scanf("%d%s%d",&new_->roll,new_->name,&new_->age);
  if(ara==p->roll
  ){
   new_->next=p;
   head=new_;
  }
  else
  {
   while ((p != NULL) && (p->roll != ara)){
    q = p;
    p = p->next;
   }
    if (p == NULL)
	{
    q->next = new_;
    new_->next = NULL;
    }
	else if(p->roll==ara)
	{
        q->next=new_;
        new_->next=p;
    }
  }
 }
 void ListSil()
 {
 	int ara;
 kisi *p,*q;
 p=head;
 printf("\nhangi roll silinecek:");scanf("%d",&ara);
 printf("**********************\n");
  if(ara==p->roll){
   head = p->next;
   free(p);
  }
  else
  {
   while ((p != NULL) && (p->roll != ara)){
    q = p;
    p = p->next;
   }
    if (p == NULL)
	{
   printf("\nVeri yok");
    }
	else if(p->roll==ara)
	{
        q->next = p->next;
		free (p);
    }
  }
 }
main(){
int secim;
	ListOlus();
	do
   {
     system("cls");

	ListGoster();
	printf("1-Ekleme 2-Silme");
	printf("\nSeciminizi giriniz:");
	scanf("%d",&secim);
	switch(secim)
	{
		case 1: ListEkle(); break;
		case 2: ListSil(); break;
	}
	} while (1);
}
