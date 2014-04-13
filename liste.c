#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
struct kisiler{
	char ad[20];
	int not;
	struct kisiler *next;
};
typedef struct kisiler kisi;
kisi *head, *new;
void Listeolustur()
{
	int i,n;
	printf("Ogrenci sayisi:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			new=(kisi *)malloc(sizeof(kisi));
			head=new;
		}
		else
		{
			new->next=(kisi *)malloc(sizeof(kisi));
			new=new->next;
		}
		printf("İsim ve notu giriniz:");
		scanf("%s %d",new->ad,&new->not);
	}
	new->next=0;
}
void ListeGoster()
{
	int sayac=1;
	kisi *p;
	p=head;
	while(p!=0)
	{
		printf("%d) %s notu %d\n",sayac,p->ad,p->not);
		sayac++;
		p=p->next;
	}
	
}
void basaekle()
{
  kisi *yeni_dugum;
  yeni_dugum = (kisi*) malloc(sizeof(kisi));
  	printf("\nAdi ve Notu: ");
        scanf("%s %d",yeni_dugum->ad,&yeni_dugum->not);

  if(head==0)
    {  head=yeni_dugum;
       yeni_dugum->next=0;
    }
     else {
             yeni_dugum->next = head;
             head=yeni_dugum;
          }
}
void sonaekle()
{
    kisi *yeni_dugum;
    yeni_dugum = (kisi*) malloc(sizeof(kisi));
        printf("\nAdi ve Notu: ");
        scanf("%s %d",yeni_dugum->ad,&yeni_dugum->not);
    if(head==0)
         { head=yeni_dugum;
           yeni_dugum->next=0;
         }
          else { 
		  kisi *son_node=head;
                 while(son_node->next != 0)
                    son_node = son_node->next;
                 son_node->next = yeni_dugum;
                 yeni_dugum->next = 0;
 
 
               }
}
void bastansil()
{
    kisi * silinecek;
    silinecek = head;
    head = head->next;
    free(silinecek);
}
void sondansil()
{
    kisi *onceki, *silinecek;
    onceki=head;
 
    while(onceki->next->next != 0)
    onceki = onceki->next;
    silinecek = onceki->next;
    onceki->next=0;
    free(silinecek);
}
int main()
{
	int secim;
	Listeolustur();
	do
   {
     system("cls");

	ListeGoster();
	printf("1-Basa ekle 2- sona ekle 3- bastan sil 4- sondan sil");
	printf("\nSeciminizi giriniz:");
	scanf("%d",&secim);
	switch(secim)
	{
		case 1:
		basaekle(); break;
		case 2:
		sonaekle(); break;
		case 3:
		bastansil();break;
		case 4:
		sondansil();break;
	}
	} while (1);
}
