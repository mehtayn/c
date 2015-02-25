// mehtayn.com
#include <stdio.h>
#include <conio.h>

int main()
{
    int sayi,rakam[30],i=0;
    printf("Bir Sayi Giriniz: ");
    scanf("%d",&sayi);
    while(sayi)
    {
        rakam[i]=sayi%10;
        sayi=sayi/10;
         printf("Girilen Sayinin Rakamlari=%d\n",rakam[i]);
   	i++;
     }
	getch();
	return 0;
}
