#include<stdio.h>
#include<string.h>
#include<conio.h>
char cumle[50];
char harf[5]={'a','e','i','o','u'};
int i=0,j=0,sayac=0,bosluk=0;
main(){
	printf("Cumleyi giriniz:");
	gets(cumle);
	for(i=0;i<strlen(cumle);i++)
	{
		if(cumle[i]==' ') bosluk++;
		for(j=0;j<strlen(cumle);j++)
			if(cumle[i]==harf[j])
			{
					sayac++;
			}
	}
	printf("girilen cumlede %d sessiz harf vardir",strlen(cumle)-sayac-bosluk);
	printf("girilen cumlede %d sesli harf vardir",sayac);
	getch();
}
