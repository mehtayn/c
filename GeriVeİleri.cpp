// mehtayn.com
//Kod Örnekleri

#include <stdio.h>
#include <conio.h>
	double x[5],y[5][5];
	double p=0.0,c=1.0,x1;
	int i,j,secim;
void geri()
{
	p+=y[4][0];
	for(int i=1;i<=4;i++)
	{
		for(int j=i;j<=4;j++)
		{
			y[j][i]=(y[j][i-1]-y[j-1][i-1])/(x[j]-x[j-i]);
		}
	}
	for(int i=1;i<=4;i++)
	{
		for(j=4;j>=5-i;j--)
		{
			c*=x1-x[j];
		}
		p+=y[4][i]*c;
		c=1.0;
	}
	printf("%lf",p);
	
}
void ileri()
{
	for(i=1; i<=4; i++) 
	{
        for(j=0; j<=4-i; j++)
		{
            y[j][i]=(y[j+1][i-1] - y[j][i-1])/(x[i+j] - x[j]);
        }
    }
	p+=y[0][0];
	for(i=1;i<=4;i++)
	{
	
		for(j=0;j<=i-1;j++)
		{
			c*=(x1-x[j]);
		}
		p+=y[0][i]*c;
		c=1.0;
	}
	printf("%lf",p);
}
int main()
{
	// n=4 olarak alınmıştır.
	x[0]=1.0;
	x[1]=1.3;
	x[2]=1.6;
	x[3]=1.9;
	x[4]=2.2;
	y[0][0]=0.7651977;
	y[1][0]=0.6200860;
	y[2][0]=0.4554022;
	y[3][0]=0.2818186;
	y[4][0]=0.1103623;
	printf("1-Geri Yonlu\n2-ileri Yonlu\nSeciminiz :");
	scanf("%d",&secim);
	printf("Bulmak istediginiz deger:");
	scanf("%lf",&x1);
	switch(secim)
	{
		case 1:
			geri();
			break;
		case 2:
			ileri();
			break;
		default:
			printf("Hatali secim");
	}
}
