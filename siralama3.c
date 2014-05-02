/*Ödev: 
Klavyeden girilen 100 tane sayıyı, 
kabarcık sıralama algoritmasını sondan başa doğru uygulayarak, 
küçükten büyüğe sıralayıp ekranda gösteren programı hazırlayınız.
*/

#include <stdio.h>
#include <conio.h>
	
int main(){
int sayi[100];
int i,j,buffer;
for(i=0;i<109;i++)
{
printf("Sayilari giriniz:");
scanf("%d",&sayi[i]);
}
for(i=0;i<99;i++)
{
	for(j=0;j<99-i;j++)
	{
		if(sayi[j]>sayi[j+1])
		{
		buffer=sayi[j];
		sayi[j]=sayi[j+1];
		sayi[j+1]=buffer;
		}
	}
}

for(i=0;i<100;i++)
{
printf("%d\n",sayi[i]);
}

	getch();
}
