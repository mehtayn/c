# mehtayn.com
Kod Örnekleri
#include <stdio.h>
int main()
{
	int gecici;
	int enkucuk;
	int i;
	int DiziSelection[5]={2,12,5,36,1};
	for (i = 0; i < 4; i++)
	{
	  enkucuk = i;
	  for (int j = (i + 1); j < 5; j++)
	  {
	    if (DiziSelection[j] < DiziSelection[enkucuk])
	    {
	      enkucuk = j;
	    }
	  }
	  gecici = DiziSelection[i];
	  DiziSelection[i] = DiziSelection[enkucuk];
	  DiziSelection[enkucuk] = gecici;
	}
	for(i=0;i<5;i++)
		printf("%d\n",DiziSelection[i]);
}
