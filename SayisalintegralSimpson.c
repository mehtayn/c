// mehtayn.com
// mehmetayhan.com.tr
//Kod Örnekleri

#include <stdio.h>
#include <conio.h>
double f(double c)
{
	return 1/c;
}
int main()
{
 	double  h,b,a,toplam,x;
 	int n;
	a=1;
	b=2;
	n=8;
	h=(b-a)/n;
	toplam=f(a)+f(b);
	for(int j=1;j<=n;j++)
	{
		x=a+j*h;
		if(j%2==1)
			toplam+=4*f(x);
		else
			toplam+=2*f(x);
	}
	toplam*=h/3;
	printf("%lf",toplam);
	getch();
}
