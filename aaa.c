#include <stdio.h>

struct listyapi
{
	char adi[21];
	struct listyapi *sonraki;
};
typedef struct listyapi dugum;
dugum *listebasi;

void basaekle(char *s)
{
	dugum *yeni_dugum;
	yeni_dugum=(dugum*) malloc (sizeof(dugum));
	strcpy(yeni_dugum->adi,s);
	if(listebasi==0)
	{
		listebasi=yeni_dugum;
		yeni_dugum->sonraki=0;
	}
	else{
		yeni_dugum->sonraki=listebasi;
		listebasi=yeni_dugum;
	}
	void sonaekle(char *s)
	{
		dugum *yeni_dugum;
		yeni_dugum=(dugum*)
		malloc(sizeof(dugum));
		strcpy(yeni_dugum->adi, s);
		if(listebasi==0)
		{listebasi=yeni_dugum;
		yeni_dugum->sonraki=0;
		}
		else
		{
			dugum *son_node=listebasi;
			while(son_node->sonraki != 0)
			son_node =son_node->sonraki;
			son_node->sonraki=yeni_dugum;
			yeni_dugum->sonraki=0;
		}
	}
	void listlist(void)
	{
		dugum *aktif_node= listebasi;
		while(aktif_node != 0)
		{
			printf("%s ",aktif_node->adi);
			aktif_node=aktif_node->sonraki;
		}
		printf("\n");
	}
	void bastansil()
	{
		dugum * silinecek;
		silinecek=listebasi;
		listebasi=listebasi->sonraki;
		free(silinecek);
	}
	void sondansil()
	{
		dugum *onceki, *silinecek;
		onceki=listebasi;
		
		while(onceki->sonraki->sonraki != 0)
		onceki=onceki->sonraki;
		silinecek=onceki->sonraki;
		onceki->sonraki=0;
		free(silinecek);
	}
	int main()
	{
		char s[21];
		char sec;
		
		do
		{
			system("cls");
			listlist();
			printf("\n 1-basa ekle \n 2-sona ekle \n 3-bastan sil \n 4 sondan sil \n 5-son \n Sec:");
			sec=getche();
			switch(sec)
			{
				case 1:	printf("\n Adi:");
				gets(s);
				basaekle(s);
				break;
				case 2: printf("\n Adi:");
				gets(s);
				sonaekle(s);
				break;
				case 3: bastansil();
				break;
				case 4: sondansil();
				break;
				case 5: return 0;
				break;
					
					
					
			}
		} while(1);
	}
}
