# mehtayn.com
//Kod Örnekleri

#include <stdio.h>
#include <math.h>
#include <conio.h>
#define e 2.7182818285
double a=1.0,b=2.0,c;
double tor=0.1;
double hata;
double f(double x)
{
	return pow(x, 4) - 9 * pow(x, 3) - 2 * pow(x, 2) + 120 * x - 130;
}
int main()
{
if(f(a)*f(b) < 0){
	do
	{
		c = (a*f(b) - b*f(a)) / (f(b) - f(a));
        if(f(a)*f(c) < 0)
        {
        	b = c;
        	hata = fabs(a-c);     	  
        }
          
        else if(f(b)*f(c) < 0)
        {
			a = c;
			hata = fabs(b-c);  
        }

        else
		{ // f(c) == 0
            printf("Aranan kök: %f",c);
            break;
        }
      
	}
        while(hata > tor);printf("Aranan kök: %f\n",c);
              
    }
	else
	{
		printf("Bu aralıkta kök yoktur.");
	}
	getch();
}
