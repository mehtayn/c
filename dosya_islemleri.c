/*text dosya (ogrenci adı,ders adı,vize,final)
1-Kayıt ekleme
2-Listeleme
3-Düzeltme(ad-notları düzelt)
4-silme(ders adı)
5-bul(ort>gecenler ve kalanların adedini yaz)
6- Çıkış
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
struct OGRENCI {
char isim[15];
int vize;
int final;
char ders[15];
}kisi[10],yedek[10],silinecek[10];
void kayit_ekle();
void ara_bul();
void listele();
void bul_degistir();
void kayit_sil();
char menu();
int sayac;
main()
{
    char secim;
    do{
    
        secim=menu();
        	system("cls");
        switch(secim)
        {
           case '1': kayit_ekle();break;
           case '2': listele();break;
           case '3':bul_degistir();break;
		   case '4':kayit_sil();break;
           case '5':ara_bul();break;
           case '6': break;
 
        }
    }while(secim<='5' && secim>='1');
 
    }
char menu(){
    char tus;
    printf("1-kayit ekle\n2-listele\n3-Duzeltme(ad-notlari duzelt)\n4-silme(ders adi)\n5-bul(ort>gecenler ve kalanlarin adedini yaz)\n6-Cikis\n");
    tus=getch();
    return tus;
}
    void kayit_ekle(){
        char tus2;
        FILE *dosya;
        dosya=fopen("a.txt","w");
 
    do{printf("%d.kisi adi giriniz :",sayac+1);
    scanf("%s",kisi[sayac].isim);
    printf("%d.kisinin dersini giriniz :",sayac+1);
    scanf("%s",kisi[sayac].ders);
    printf("%d.kisi vizesi giriniz :",sayac+1);
    scanf("%d",&kisi[sayac].vize);
    printf("%d.kisi finali giriniz :",sayac+1);
    scanf("%d",&kisi[sayac].final);
	fflush(stdin);
    printf("\nyeni kayit icin 'e' basin ve menuye donmek icin herhangi bir tusa basin");
    tus2=getch();
 
fprintf(dosya,"%s\t%s\t%d\t%d\n",kisi[sayac].isim,kisi[sayac].ders,kisi[sayac].vize,kisi[sayac].final);
sayac++;
    }while(tus2=='e' || tus2=='E');
fclose(dosya);
}
void listele(){
FILE *dosya;
dosya=fopen("a.txt","r");
int a=0,i;
while(!feof(dosya)){
    fscanf(dosya,"%s%s%d%d",yedek[a].isim,yedek[a].ders,&yedek[a].vize,&yedek[a].final);
a++;      
}
for(i=0;i<(a-1);i++)
printf("%d\t%s\t%s\t%d\t%d\n",i+1,yedek[i].isim,yedek[i].ders,yedek[i].vize,yedek[i].final);
fclose(dosya);
}
void ara_bul(){
FILE *dosya;
dosya=fopen("a.txt","r");
int a=0,i,ort[30],k;
while(!feof(dosya)){
    fscanf(dosya,"%s%s%d%d",yedek[a].isim,yedek[a].ders,&yedek[a].vize,&yedek[a].final);
    ort[a]=(yedek[a].vize*4/10)+(yedek[a].final*6/10);
a++;    
 }
for(i=0;i<(a-1);i++){
 if(ort[i]>=60)
        {
        	k=i;
printf("%d\t%s\t%s\t%d\t%d\n",i+1,yedek[i].isim,yedek[i].ders,yedek[i].vize,yedek[i].final);
}
}
printf("%d kisi kalmistir.\n",a-k-2);
fclose(dosya);
}
void bul_degistir(){
    char kelime[150];
printf("\nDegisecek Kisiyi girin :");
scanf("%s",&kelime);
FILE *dosya;
dosya=fopen("a.txt","r");
int a=0,i;
while(!feof(dosya)){
    fscanf(dosya,"%s%s%d%d",yedek[a].isim,yedek[a].ders,&yedek[a].vize,&yedek[a].final);
a++;     
}
for(i=0;i<(a-1);i++){
 if(strcmp(kelime,yedek[i].isim)==0)
        {
            printf("%d. kisinin adini giriniz :",i+1);
            scanf("%s",yedek[i].isim);
            printf("%d. kisinin dersini giriniz :",i+1);
            scanf("%s",yedek[i].ders);
            printf("%d. kisinin vizesini giriniz :",i+1);
            scanf("%d",&yedek[i].vize); 
            printf("%d. kisinin Finalini giriniz :",i+1);
            scanf("%d",&yedek[i].final);
            fflush(stdin);
 
}
}
fclose(dosya);
 

FILE *dosya2;
dosya2=fopen("a.txt","w");
int i2;
for(i2=0;i2<(a-1);i2++){
fprintf(dosya2,"%s\t%s\t%d\t%d\n",yedek[i2].isim,yedek[i2].ders,yedek[i2].vize,yedek[i2].final);
}
fclose(dosya2);
}
 
 
void kayit_sil(){
char kelime[150];
printf("\nSilinecek Dersi girin :");
scanf("%s",&kelime);
FILE *dosya;
dosya=fopen("a.txt","r");
int a=0,i=0,kacinci;
while(!feof(dosya)){
    fscanf(dosya,"%s%s%d%d",yedek[a].isim,yedek[a].ders,&yedek[a].vize,&yedek[a].final);
a++;     
}
 
for(i=0;i<(a-1);i++){
 if(strcmp(kelime,yedek[i].ders)==0)
        {            kacinci=i;
                   }
 
}
for(i=0;i<(kacinci);i++){
    strcpy(silinecek[i].isim,yedek[i].isim);

    strcpy(silinecek[i].ders,yedek[i].ders);

    silinecek[i].vize=yedek[i].vize;

    silinecek[i].final=yedek[i].final;

}

for(i=(kacinci+1);i<=(a-1);i++){
    strcpy(silinecek[i-1].isim,yedek[i].isim);
    strcpy(silinecek[i-1].ders,yedek[i].ders);
    silinecek[i-1].vize=yedek[i].vize;
    silinecek[i-1].final=yedek[i].final;
}
 
 
fclose(dosya);
 

FILE *dosya2;
dosya2=fopen("a.txt","w");
int i2;
for(i2=0;i2<(a-1);i2++){
fprintf(dosya2,"%s\t%s\t%d\t%d\n",silinecek[i2].isim,silinecek[i2].ders,silinecek[i2].vize,silinecek[i2].final);
}
fclose(dosya2);
 
}
