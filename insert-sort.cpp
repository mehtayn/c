# mehtayn.com
Kod Örnekleri

#include <stdio.h>
int main()
{

	int gecici;
	int onceki;
	int DiziInsert[5]={2,12,5,36,1};
	for (int j = 1; j < 5; j++)
	{
	    gecici = DiziInsert[j]; onceki = j - 1; while (onceki >= 0 && DiziInsert[onceki] > gecici)
	    {
	    	DiziInsert[onceki + 1] = DiziInsert[onceki];
	        onceki--;
	    }
	    DiziInsert[onceki + 1] = gecici;
	}
	for(int i=0;i<5;i++)
		printf("%d\n",DiziInsert[i]);
}
