#include <stdio.h>

struct ogrenci_bilgileri
{
char ders_adi[20];
int ders_final;
};
struct ogrenci_bilgileri a[10];

int i,j,k,ders_sayisi,sayac=0;


void verigir(), veriyaz(),sonuc();

int main()
{
	printf("Kac Ders girilecek:");
	scanf("%d",&ders_sayisi);
verigir();
veriyaz();
sonuc();
getch();
return 0;
}

void verigir()
{
for(i=0;i<ders_sayisi;i++)
{
printf("%d. Ders adi : ",i+1);
scanf("%s", &a[i].ders_adi);
printf("\n%d. Dersin finali : ",i+1);
scanf("%d", &a[i].ders_final);

printf("\n");
}
}

void veriyaz()
{
for(j=0;j<ders_sayisi;j++)
{
printf("Ders Adi: %s  final: %d \n", a[j].ders_adi,a[j].ders_final);
}
}
void sonuc()
{
	printf("Dersi gecenler\n");
for(k=0;k<ders_sayisi;k++)
{
		if(a[k].ders_final>=60){
	
printf("Ders Adi: %s  final: %d \n", a[k].ders_adi,a[k].ders_final);
	}
}
}

