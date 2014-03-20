#include <stdio.h>

struct ogrenci_bilgileri
{
char ders_adi[20];
int ders_vize;
int ders_final;
};
struct ogrenci_bilgileri a[10];

int i,b,d=100,f,c,secim,cik;
char x;

void verigir(), veriyaz();

int main()
{
verigir();

printf("1-Topla\n");
printf("2-Cikar\n");
printf("Seciminizi giriniz:");
scanf("%d",&secim);
switch(secim)
{
	case 2:
		{
		
		printf("Kac numaralı ders cikarilsin:");
		scanf("%d",&cik);
		x=malloc(sizeof(char a[cik].ders_adi))
		free(x);break;
	}
}
veriyaz();
getch();
return 0;
}

void verigir()
{
for(i=0;i<=2;i++)
{
printf("%d. Ders adi : ", i+1);
scanf("%s", &a[i].ders_adi);
printf("\n%d.Dersin vizesi :",i+1);
scanf("%d", &a[i].ders_vize);
printf("\n%d. Dersin finali : ", i+1);
scanf("%d", &a[i].ders_final);

printf("\n");
}
}

void veriyaz()
{
for(b=0;b<=2;b++)
{
printf("%s vize:%d final: %d \n", a[b].ders_adi, a[b].ders_vize,a[b].ders_final);
}
}
