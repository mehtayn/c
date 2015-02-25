www.mehtayn.com

#include "stdio.h"
#include "conio.h"
#include "stdlib.h"//free ve malloc fonksiyonlarımızın çalışması için gereken kütüphanelerimiz
struct dugum //dugum adlı yeni bir yapı tanımlıyoruz.
{
	int veri;//dugum adlı yapımızın değişkenleri
	dugum *sonraki;//dugum yapımızın bir sonraki veriyi göstermek amacıyla kullanacagımız pointer değişkenimiz
};
dugum *basaekle(dugum *head) //yapımıza baştan ekleme yapılacaksa
{
	dugum *gecici=(dugum *)malloc(sizeof(dugum));//yeni bir eleman eklediğimiz için gecici adlı değişkenimize dinamik bellekte yer ayırıyoruz
	gecici->veri=8;//gecici değişkenimizin verisine 8 değerini atadık.
	gecici->sonraki=head; //gecici değişkenimizin bir sonraki elemanı head ı göstersin
	head=gecici;//yeni head imizde gecici olsun. Böylelikle basa eklenmiş olucak
	return head;// fonksiyonu cağırdıgımız yere head imizi döndürecek.
}
dugum *sonaekle(dugum *head) //yapımıza sondan ekleme yapılacaksa
{
	dugum *gecici=(dugum *)malloc(sizeof(dugum));//yeni bir eleman eklediğimiz için gecici adlı değişkenimize dinamik bellekte yer ayırıyoruz
	gecici-> veri=7;//gecici değişkenimizin verisine7 değerini atadık.
	gecici->sonraki=NULL;//sona ekleme yaptıgımız için bu sefer gecici değişenimizin bir sonraki elemanını NULL yaptık.
	dugum *gecici2=head;//yeni bir gecici2 değişkenini head i tanımladık.
	while(gecici2->sonraki!=NULL)//while döngüsü ile head ten yani baştan sona kadar döndürme işlemi ile son elemanı bulucak
								//Bunuda gecici2 değişkenimize atacak
		gecici2=gecici2->sonraki;//NULL eşit olmayıncaya kadar bir sonrakine gittik.
	gecici2->sonraki=gecici;//gecici2 değişkenimizden sonra gecici yani bizim eklediğimiz değişkeni göstersin dedik.
	return head;// fonksiyonu cağırdıgımız yere head imizi döndürecek.
}
void goster(dugum *head) // Yapımızın tüm elemanlarını gösteren fonksiyon
{
	if(head==NULL)//yani hiçbir veri girilmemişse çalışak olan fonksiyon
	{
		printf("Liste Boş\n");
		return ;
	}
	dugum *gecici2=head;//gecici2 adlı değişkenimizi head eşitledik.Bunuda başlangıc sonuna kadar olan verileri bulmak için kullancagız.
	while(gecici2 != NULL)//gecici2 adlı elemanızı baştan sona kadar döndürecek
	{
		printf("%d\n",gecici2->veri);//yazdırma işlemi
		gecici2=gecici2->sonraki;//gecisi2 elemanımız NULL oluncaya kadar bir sonrakini tanımlıyacak
	}
}
int say(dugum *head) //listeyi kaç veri eklendiğinin sayısı veren fonksiyon
{//algoritma olarak gösterme ile aynı sadece while döngüsün içine bir sayac ile saydırıcaz.
	if(head==NULL)//listemiz boş ise
	{
		printf("Liste Boş\n");
		return 0;
	}
	dugum *gecici2 =head;//gecici2 adlı değişkenimizi head eşitledik.Bunuda başlangıc sonuna kadar olan verileri bulmak için kullancagız.
	int counter = 0;//sayacımızı 0 başlatıyoruz
	while(gecici2 != NULL)//gecici2 adlı elemanızı baştan sona kadar döndürecek
	{
		counter++;//sayacımız gecici2 null olana kadar 1 artacak
		gecici2=gecici2->sonraki;//gecisi2 elemanımız NULL oluncaya kadar bir sonrakini tanımlıyacak
	}
	return counter;// fonksiyonu cağırdıgımız yere sayacımızı döndürecek.
}
void rec_goster(dugum *head) //recursive fonksiyon=kendi kendini çagıran fonksiyondur.tüm elemanlarını gösteren fonksiyon
{
	if(head==NULL) return; //listemiz boş ise
	else
	{
		printf("%d\n",head->veri);//head imiz verisini göstercek
		rec_goster(head->sonraki);//recursive fonksiyonumuz kendisi çagıracak ancak head imiz bir sonrakini
	}
}
dugum *sil(struct dugum *head,int key)//istenilen elemanımızı silen fonksiyon
{
	dugum *gecici=head;//gecici adlı değişkenimizi head eşitledik.Başlangıc elemanımzdan sona kadar gitmek için kullancagız
	if(head->veri==key)//Eğer ilk elemanımız sileceğimiz elemana eşitse
	{
		head=head->sonraki;//ilk elemanımızın bir sonraki artık ilk elemanız yani head imiz yap dedik
		free(gecici);//head imizi silersek kaybolur bu yüzden gecici elemanımızı siliyoruz
	}
	else
	{
		while(gecici->sonraki->veri!=key)//gecicimiz bir sonraki elemanız girdiğimiz elemana eşit oluncaya kadar
			gecici=gecici->sonraki;//bir ileri götürecek
		struct dugum *gecici2=gecici->sonraki;//giridiğimiz elemanı buldugumuzda bunu yeni bir gecici2 adlı değişkenimize atadık
		gecici->sonraki=gecici->sonraki->sonraki;//sileceğimiz elemanda artık ondan sonra elemanı gösterecek
		free(gecici2);//gecici2 değişkenimizi sildik
	}
	return head;
}
void ters(struct dugum *p)//Aynı resursive fonksiyon ile göstermenın tersten yazdırılış fonksiyonu
{
	if(p==NULL) return ;//listemiz boş ise
	ters(p->sonraki);//recursive fonksiyonumuz kendisi çagıracak ancak p imiz bir sonrakini
	printf("%d\n",p->veri);// p mizin verisini yazdırıcak
}
int main()
{
dugum *head;
	head =(dugum *)malloc(sizeof(dugum));
	head->veri=2;
	head->sonraki=NULL;
	head->sonraki=(dugum *)malloc(sizeof(dugum));
	head->sonraki->veri=5;
	head->sonraki->sonraki=NULL;
	printf("ilk liste\n");
	goster(head);
	printf("Eleman sayisi %d\n",say(head));
	head=basaekle(head);
	head=sonaekle(head);
	head=sonaekle(head);
	goster(head);
	printf("Eleman sayisi %d\n",say(head));
	sil(head,5);
	sil(head,2);
	sil(head,7);				
	rec_goster(head);
	printf("***************************\nTersten Yaz\n");
	ters(head);
	getch();

}
