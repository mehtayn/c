/*	Ödev:
	24 kişilik bir sınıfta bulunan öğrencilerin 
	numaraları ve matematik dersinden aldıkları 
	puanlar bir diziye klavyeden giriliyor. 
	Bu sınıftaki öğrencilerin numaralarını 
	ve puanlarını, seçim algoritması kullanarak 
	aldıkları puana göre küçükten büyüğe sıralayıp, 
	ekranda gösteren programı hazırlayınız.
*/

#include <stdio.h>
#include <conio.h>

struct ogrenciler{
int no[24];
int mnot[24];
}ogrenci;

void selection(int k){
int i,j,buffer,buffer2;
for(i=0;i<k-1;i++){
for(j=i+1;j<k;j++){
if(ogrenci.mnot[i]>ogrenci.mnot[j])
{
buffer=ogrenci.mnot[i];
ogrenci.mnot[i]=ogrenci.mnot[j];
ogrenci.mnot[j]=buffer;
buffer2=ogrenci.no[i];
ogrenci.no[i]=ogrenci.no[j];
ogrenci.no[j]=buffer2;
}
}
}
}

main(){
int N,i;
printf("Kac kisilik sinif:");scanf("%d",&N);

for(i=0;i<N;i++){
printf("Ogrenci No:");
scanf("%d",&ogrenci.no[i]);
printf("\nMat ders Notu:");
scanf("%d",&ogrenci.mnot[i]);
}
printf("******************************\n");
puts("SIRALANMAMIS HALI\n");
for(i=0;i<N;i++){
printf("Ogrenci No:%d----Mat ders notu: %d\n",ogrenci.no[i],ogrenci.mnot[i]);
}
selection(N);

//Sıralanmamış hali:
printf("******************************\n");
puts("SIRALANMIS HALI\n");
for(i=0;i<N;i++){
printf("Ogrenci No:%d----Mat ders notu: %d\n",ogrenci.no[i],ogrenci.mnot[i]);
}




getch();
}
