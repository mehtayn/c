# mehtayn.com
//Kod Örnekleri

#include <stdio.h>
#include <math.h>
#include <conio.h>
#define e 2.7182818285
double a = 0.0, b = 1.0, c;
double tor = 0.1;
double hata;
double f(double x)
{
	return pow(e, x) - 3 * x;
}
int main()
{
	if (f(a)*f(b) < 0){
		do
		{
			c = (a + b) / 2;
			if (f(a)*f(c) < 0)
			{
				b = c;
				hata = fabs(a - c);
			}

			else if (f(b)*f(c) < 0)
			{
				a = c;
				hata = fabs(b - c);
			}

			else
			{ // f(c) == 0
				printf("Aranan kök: %f", c);
				break;
			}

		} while (hata > tor); printf("Aranan kök: %f\n", c);

	}
	else
	{
		printf("Bu aralıkta kök yoktur.");
	}
	getch();
}
