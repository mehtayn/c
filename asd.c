/*
	Klavyeden girilen 3x4 matrisin jacobi ve gauss siedel yöntemiyle çözen program
	
*/
#include <stdio.h>
#include <conio.h>
#include <math.h>
double tor=0.0001,hata,hata1,hata2,hata3;	

double jacobi(double a1[7],double a2[7],double a3[7],int b[3][4])
{
	int i=0;
	do
	{
		a1[i+1]=(b[0][3]-b[0][1]*a2[i]-b[0][2]*a3[i])/b[0][0]; 
		a2[i+1]=(b[1][3]-b[1][0]*a1[i]-b[1][2]*a3[i])/b[1][1];
		a3[i+1]=(b[2][3]-b[2][0]*a1[i]-b[2][1]*a2[i])/b[2][2];
		
		hata1=fabs(a1[i+1]-a1[i]);
		hata2=fabs(a2[i+1]-a2[i]);
		hata3=fabs(a3[i+1]-a3[i]);
		
		if(hata1>hata2 || hata1>hata3) hata=hata1;
		else if(hata2>hata1 || hata2>hata3) hata=hata2;
		else if(hata3>hata2 || hata3>hata1) hata=hata3;
		
		printf("x1[%d]=%lf\n",i+1,a1[i+1]);
		printf("x2[%d]=%lf\n",i+1,a2[i+1]);
		printf("x3[%d]=%lf\n",i+1,a3[i+1]);
		printf("Hata=%lf\n",hata);
		printf("---------------------\n");
		i++;
	}while(hata>tor);

}
double gauss(double a1[7],double a2[7],double a3[7],int b[3][4])
{

	int i=0;
	do
	{
		a1[i+1]=(b[0][3]-b[0][1]*a2[i]-b[0][2]*a3[i])/b[0][0]; 
		a2[i+1]=(b[1][3]-b[1][0]*a1[i+1]-b[1][2]*a3[i])/b[1][1];
		a3[i+1]=(b[2][3]-b[2][0]*a1[i+1]-b[2][1]*a2[i+1])/b[2][2];
		
		hata1=fabs(a1[i+1]-a1[i]);
		hata2=fabs(a2[i+1]-a2[i]);
		hata3=fabs(a3[i+1]-a3[i]);
		
		if(hata1>hata2 || hata1>hata3) hata=hata1;
		else if(hata2>hata1 || hata2>hata3) hata=hata2;
		else if(hata3>hata2 || hata3>hata1) hata=hata3;
		
		printf("x1[%d]=%lf\n",i+1,a1[i+1]);
		printf("x2[%d]=%lf\n",i+1,a2[i+1]);
		printf("x3[%d]=%lf\n",i+1,a3[i+1]);
		printf("Hata=%lf\n",hata);
		printf("---------------------\n");
		i++;
	}while(hata>tor);

}
main()
{
	int secim;

	double x1[7],x2[7],x3[7];
	int x[3][4];
	x1[0]=0.0;
	x2[0]=0.0;
	x3[0]=0.0;
	printf("3x3 luk matrisi ve sonucunu 3x4 şeklinde giriniz:");
	for(int j=0;j<3;j++)
	{
		for(int m=0;m<4;m++)
		{
			scanf("%d",&x[j][m]);

		}

	}

	printf("1-jacobi \n2-gauss-siedel\n");
	scanf("%d",&secim);
	switch(secim)
	{
		case 1:
			jacobi(x1,x2,x3,x);
			break;
		case 2:
			gauss(x1,x2,x3,x);
			break;		
	}
	getch();
	return 0;
	
}
