/*Ödev:
Bir sayı dizisinde 10 adet sayı küçükten büyüğe sıralanmış olarak tutulmaktadır. 
Bu sayı dizisine dışarıdan 4 tane eleman girilecek fakat her eleman sıralama bozulmadan uygun konuma yerleştirilecektir. 
Bu işlemi yapan programı hazırlayınız.
*/

#include <stdio.h>
#include <conio.h>
	
int main(){
int sayi[14]={5,12,48,60,90,120,160,180,200,210};
int i,j,buffer;
for(i=10;i<14;i++)
{
	printf("Sayiyi giriniz:");
	scanf("%d",&sayi[i]);
}

for(i=1;i<14;i++)
{
buffer=sayi[i];
j=i;
while(j>0 && sayi[j-1]>buffer)
{
sayi[j]=sayi[j-1];
j--;
}
sayi[j]=buffer;
}
for(i=0;i<14;i++)
{
printf("%d\n",sayi[i]);
}

	getch();
}
