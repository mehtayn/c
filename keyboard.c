#include <stdio.h>
#include <conio.h>
#include <windows.h>
main()
{

BYTE deger[256];
	puts("durumlar");
	GetKeyboardState(deger);
	if(deger[20] & 1)
		printf("caps lock acik");
	else
		printf("caps lock kapali");
	if(deger[144] & 1)
		printf("\nnum lock acik");
	else
		printf("\nnum lock kapali");
	getch();
	
}
