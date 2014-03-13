#include <stdio.h>
#include <string.h>
int sayi,toplam=0,i;
int tektopla(int); 
int main()

{
	printf("Sayi giriniz:");
	scanf("%d",&sayi);
	tektopla(sayi);
	printf("%d",toplam);
}
tektopla(int x)
{
	for(i=1;i<=x;i+=2)
	toplam+=i;
	return toplam;
}
