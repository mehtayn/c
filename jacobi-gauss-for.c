// mehtayn.com
// Kod Örnekleri
/*
	Jacobi ve gauss-siedel yöntemini for döngüsü ile çözen program
	10x1+3x2+x3=14  x1[i+1]=(14-3*x2[i]-x3[i])/10
	2x1-10x2+3x2=-5 x2[i+1]=(2*x1[i]+3*x3[i]+5)/10;
	x1+3x2+10x3=14  x3[i+1]=(14-x1[i]-3*x2[i])/10;
*/
#include <stdio.h>
#include <conio.h>
double jacobi(double a1[7],double a2[7],double a3[7])
{
	for(int i=0;i<6;i++)
	{
		a1[i+1]=(14-3*a2[i]-a3[i])/10;
		a2[i+1]=(2*a1[i]+3*a3[i]+5)/10;
		a3[i+1]=(14-a1[i]-3*a2[i])/10;
		
		printf("x1[%d]=%lf\n",i+1,a1[i+1]);
		printf("x2[%d]=%lf\n",i+1,a2[i+1]);
		printf("x3[%d]=%lf\n",i+1,a3[i+1]);
		printf("---------------------\n");
	}

}
double gauss(double a1[7],double a2[7],double a3[7])
{
	for(int i=0;i<6;i++)
	{
		a1[i+1]=(14-3*a2[i]-a3[i])/10;
		a2[i+1]=(2*a1[i+1]+3*a3[i]+5)/10;
		a3[i+1]=(14-a1[i+1]-3*a2[i+1])/10;
		
		printf("x1[%d]=%lf\n",i+1,a1[i+1]);
		printf("x2[%d]=%lf\n",i+1,a2[i+1]);
		printf("x3[%d]=%lf\n",i+1,a3[i+1]);
		printf("---------------------\n");
	}

}
main()
{
	int secim;
	double x1[7],x2[7],x3[7];
	x1[0]=0.0;
	x2[0]=0.0;
	x3[0]=0.0;
	printf("1-jacobi \n2-gauss-siedel\n");
	scanf("%d",&secim);
	switch(secim)
	{
		case 1:
			jacobi(x1,x2,x3);
			break;
		case 2:
			gauss(x1,x2,x3);
			break;		
	}
	getch();
	return 0;
	
}
