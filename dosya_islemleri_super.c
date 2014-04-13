#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
struct kisiler{
	char name[30];
	int note;
}kisi;
void olustur(){
	int i,n;
	FILE *dosya;
	printf("Ogrenci sayisi:");
	scanf("%d",&n);
	dosya=fopen("dosya.txt","w");
	for(i=0;i<n;i++)
	{
fflush(stdin);
printf("Adi giriniz:");
gets(kisi.name);
printf("Notu giriniz:");
scanf("%d",&kisi.note);
fprintf(dosya,"%s %d\n",kisi.name,kisi.note);
	}
fclose(dosya);
}
void Goster()
{
	int i;
FILE *dosya;
dosya=fopen("dosya.txt","r");
while(!feof(dosya))
{
	fflush(stdout);

	
fscanf(dosya,"%s %d\n",&kisi.name,&kisi.note);	

printf("\n");
printf("%s %d\n",kisi.name,kisi.note);

}
fclose(dosya);
}
void arama()
{
	fflush(stdin);
	char arama[30];
	FILE *dosya;

	printf("İsim giriniz:");
	scanf("%s",arama);
	dosya=fopen("dosya.txt","r");
		
			
	while(!feof(dosya))
	{
		fscanf(dosya,"%s %d\n",&kisi.name,&kisi.note);
		if(strcmp(arama,kisi.name)==0)
		{
		printf("%s %d\n",kisi.name,kisi.note);
		}
	}
	fclose(dosya);
	
}
void silme(){
 FILE *dosya;
 FILE *yedek;
 char sil[23];
 dosya=fopen("dosya.txt","r");
 yedek=fopen("yedek.txt","a");
 printf("Silinecek ismi giriniz:");
 scanf("%s",sil);
 while(!feof(dosya)){
  fscanf(dosya,"%s %d\n",kisi.name,&kisi.note);
  if(strcmp(sil,kisi.name)!=0){
   fprintf(yedek,"%s %d\n",kisi.name,kisi.note);
  }

  }
  fclose(dosya);
  fclose(yedek);
  remove("dosya.txt");
  rename("yedek.txt","dosya.txt");
 fflush(stdin);
}
void degistir(){
 FILE *dosya;
 FILE *yedek;
 char degis[40];
 dosya=fopen("dosya.txt","r");
 yedek=fopen("yedek.txt","w");
 printf("Degisecek ismi giriniz:");
 scanf("%s",degis);
 while(!feof(dosya))
 {
  fscanf(dosya,"%s %d\n",kisi.name,&kisi.note);
  if(strcmp(degis,kisi.name)!=0){
   fprintf(yedek,"%s %d\n",kisi.name,kisi.note);
  }
  else if(strcmp(degis,kisi.name)==0){
   fflush(stdin);
   printf("Adi giriniz:");
   scanf("%s",kisi.name);
   printf("Notu giriniz:");
   scanf("%d",&kisi.note);
   fprintf(yedek,"%s %d\n",kisi.name,kisi.note);
  }
 }
 fclose(yedek);
 fclose(dosya);
 remove("dosya.txt");
 rename("yedek.txt","dosya.txt");
}
void ekle()
{
	FILE *dosya;
	dosya=fopen("dosya.txt","a+");
	printf("ismi giriniz:");
	scanf("%s",kisi.name);
	printf("notu giriniz:");
	scanf("%d",&kisi.note);
	fprintf(dosya,"%s %d\n",kisi.name,kisi.note);
	fclose(dosya);
}

main()
{
int secim;
olustur();
do{
	system("cls");
	Goster();
	printf("1-Arama 2-Silme 3-Degistirme 4-Ekle");
	scanf("%d",&secim);
	
	switch(secim)
	{
		case 1: arama(); break;
		case 2: silme(); break;
		case 3: degistir(); break;
		case 4: ekle(); break;
	}
	
}while(1);
}
