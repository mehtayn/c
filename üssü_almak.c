#include <stdio.h>

int taban,kuvvet,x;
int UsAl(int, int);
int main(void){
	printf("Taban ve kuvveti giriniz:");
	scanf("%d %d",&taban,&kuvvet);
	Usal(taban,kuvvet);
	printf("%d",x);
}
Usal(int i,int j)
{
	x=pow(i,j); 
	return x;
}
