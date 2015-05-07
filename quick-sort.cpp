# mehtayn.com
Kod Örnekleri

#include <stdio.h>
int QuickSort(int integerList[], int start, int end, int pivot)
{
	if (start < end)
  {
    pivot = integerList[end];
    int location = start;
    int bound = end;
    while (location < bound)
    {
      if (integerList[location] < pivot)
      location++;
      else
      {
        integerList[bound] = integerList[location];
        integerList[location] = integerList[bound - 1];
        bound--;
      }
    }
    integerList[bound] = pivot;
    QuickSort(integerList, start, bound - 1, pivot);
    QuickSort(integerList, bound + 1, end, pivot);
  }
}
int main()
{
	int DiziQuick[5]={2,12,5,36,1};
	QuickSort(DiziQuick,0,4,4);
	for (int i = 0; i < 5; i++)
  {               
  	 printf("%d\n",DiziQuick[i]);
  }
}
