#include<stdio.h>
char string[100];
int i,j,k,a=1,m=1;
int kackerecikti[100]={0};
main(){
	puts("ifadenizi giriniz");
	gets(string);
	while(string[a]!='\0'){
m++;
a++;
}
for(i=0;i<m;i++){
if(kackerecikti[i]==0)
{
for(j=i+1;j<m;j++)
{
if(string[j]!=' ' && string[j]==string[i])
{
kackerecikti[i]++;
kackerecikti[j]++;
}
}
if(string[i]!=' ')
printf("%c %d tane\n",string[i],kackerecikti[i]+1);
}
}
}
