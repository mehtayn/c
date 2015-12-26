// mehtayn.com
// mehmetayhan.com.tr
// Kod Örnekleri

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
 	for(int i=1;i<=n-1;i++)
 	{
 		x=a+i*h;
 		toplam+=2*f(x);
 	}
 	toplam*=h/2;
 	printf("%lf",toplam);
 	getch();
}
