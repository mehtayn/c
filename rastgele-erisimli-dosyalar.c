#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ogrenci
{
 char k;
 char num[10];
 char adsoyad[30];
 char tel[16];
 }ogrkay;

FILE *dosya,*yedek;
int i, kaysay, say;
long kayit_yer;
char cev,c;

int ksay(void)
{
return ((filelength(fileno(dosya))/sizeof(struct ogrenci)));
}

void kayit_ekle(void)
{
  dosya = fopen("ogrenci.dat","r+b");
  if (dosya == NULL)
  dosya = fopen("ogrenci.dat","w+b");
  system("cls");
  fflush(stdin);
  printf("Numara:");
  gets(ogrkay.num);
  printf("Ad:");
  gets(ogrkay.adsoyad);
  printf("Tel:");
  gets(ogrkay.tel);
  printf("Girilen Bilgiler Dogru mu? [E/H]");
  cev=getche();

  if(cev=='E' || cev=='e')
  {
   ogrkay.k='*';
   fseek(dosya,filelength(fileno(dosya)),SEEK_SET);
    fwrite(&ogrkay,sizeof(struct ogrenci),1,dosya);
  }
fclose(dosya);
}

void baslik(void)
{
 system("cls");
 if(dosya==NULL) printf("Dosya acilamadi");
 printf("%-10s %-30s %-16s \n\n","NUMARA","AD SOYAD", "TELEFON");
 say=0;
}

void listele(void)
{
 int i;
 dosya = fopen("ogrenci.dat","rb");
 baslik();
 kaysay=ksay();
 fseek(dosya,0,SEEK_SET);
 for(i=0; i<kaysay; i++)
 {
  fseek(dosya,(i*sizeof(struct ogrenci)),SEEK_SET);
  fread(&ogrkay,sizeof(struct ogrenci),1,dosya);
  if(ogrkay.k=='*')
    {
     say++;
     printf("%-10s",ogrkay.num);
     printf("%-30s",ogrkay.adsoyad);
     printf("%-16s\n",ogrkay.tel);
     if(say==20)
     {
      printf("Diger sayfaya gecmek icin bir tusa basiniz");
      getch();
      baslik();
     }
    }
 }
 printf("\nToplam Kayit Sayisi= %d",kaysay);
 printf("\n\nListelenecek kayitlar bitti...");
 fclose(dosya);
 getch();
}

void silme(){
 char sil[30];
 int i;
 dosya = fopen("ogrenci.dat","rb");
 yedek = fopen("yedek.dat","ab");
 printf("Silinecek ismi giriniz:");
  scanf("%s",sil);
  kaysay=ksay();
 for(i=0; i<kaysay; i++){
  fseek(dosya,(i*sizeof(struct ogrenci)),SEEK_SET);
  fread(&ogrkay,sizeof(struct ogrenci),1,dosya);
  if(strcmp(sil,ogrkay.adsoyad)!=0){
   ogrkay.k='*';
   fseek(yedek,filelength(fileno(yedek)),SEEK_SET);
   fwrite(&ogrkay,sizeof(struct ogrenci),1,yedek);
  }
 }
 printf("%s silinmistir.\nDevam etmek icin bir tusa basiniz.",sil);
 fclose(dosya);
   fclose(yedek);
   remove("ogrenci.dat.");
   rename("yedek.dat","ogrenci.dat");
}
 
 


int main(){
do
{
 system("cls");
 printf("1-Bilgi girisi \n2-Bilgi Listeleme \n3-Sil \n4-Cikis \n\nSecim:");
 c=getche();
 switch(c)
 {

 case '1': kayit_ekle(); break;
 case '2': listele(); break;
 case '3': silme(); break;
 case '4': exit(0); break;
  }
}
 while(1);
 getch();
}
