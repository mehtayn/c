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
int main(){
	int N;
	int i,j,buffer;
	int ders[25];
	printf("Kac kisilik sinif:");scanf("%d",&N);
	for(i=0;i<N;i++){
		printf("\n%d.Ogrenci ders notu giriniz:",(i+1));
		scanf("%d",&ders[i]);
	}
	printf("******************************\n");
	puts("SIRALANMAMIS HALI\n");
		//Sıralanmamış hali:
		for(i=0;i<N;i++){
		printf("%d.Ogrenci ders notu: %d\n",(i+1),ders[i]);
	}
	//SIRALAMA ALGORİTMASI
	
	for(i=0;i<N-1;i++){
	for(j=i+1;j<N;j++)
		{
		if(ders[i]<ders[j])
						{
						buffer=ders[i];
						ders[i]=ders[j];
						ders[j]=buffer;
						}
	}
}
printf("******************************\n");
puts("SIRALANMIS HALI\n");
		//Sıralanmış hali:
		for(i=0;i<N;i++){
		printf("%d.Ogrenci ders notu: %d\n",(i+1),ders[i]);
	}
	
	return N;
	getch();
}
