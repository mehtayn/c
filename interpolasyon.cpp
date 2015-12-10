// mehtayn.com
//Kod Örnekleri
#include <stdio.h>
#include <conio.h>
#include <math.h>
#define e 2.718281
double karekok(double m)
{
	return sqrt(pow(e,m));
}
int main()
{
	double xa;
	double x[10];
	double f[10];
	double l[10]={1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0};
	double p=0.0;
	int n;
	double hata;
	printf("n=");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		printf("x[%d] degerini giriniz: ",i);
		scanf("%lf",&x[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		printf("f[%d] degerini giriniz: ",i);
		scanf("%lf",&f[i]);
	}
	printf("aranan degerleri giriniz: ");
	scanf("%lf",&xa);
	for(int k=0;k<3;k++)
	{
		for(int j=0;j<3;j++)
		{
			if(j!=k)
			{
				l[k]*=(xa-x[j])/(x[k]-x[j]);
			}
		}
		p+=f[k]*l[k];
	}
	printf("p(0.7)=%lf\n",p);
	hata=fabs(p-karekok(xa));
	printf("hata=%lf",hata);
}
