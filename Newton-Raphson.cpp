# mehtayn.com
//Kod Örnekleri
#include <stdio.h>
#include <math.h>
#include <conio.h>
#define e 2.7182818285
double x0 = 1.0, x1;
double tor=0.00001;
double hata=1;
double f(double x)
{
	return pow(x, 3)-x-1;
}
double ft(double x)
{
	return 3*pow(x, 2)-1;
}
int main()
{
	while (hata > tor)
	{
		x1 = x0 - f(x0)/ft(x0);
		hata = fabs(x1 - x0);
		x0 = x1;
	}
	printf("%f",x1);
	getch();
}
