#include <stdio.h>
#include <conio.h>
int sayi[],i=0,sayac=0;
int main() {
	while(1)
	{
	
	printf("Sayilari giriniz:");
	scanf("%d",&sayi[sayac]);
	if(sayi[sayac]==0)	{break;}

	else
	{
		sayac++;
	}
	}
	for(i=0;i<sayac;i++)
	printf("%d. sayi : %d  \n",i+1,sayi[i]);
	getch();
	return 0;
}
