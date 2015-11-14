// mehtayn.com
//Kod Örnekleri

#include <stdio.h>
#include <conio.h>
double a[3][4];
double temp;
void goster(double k[3][4])
{
	printf("\n Son durum: \n");
	for (int m = 0; m<3; m++)
	{
		for (int n = 0; n<4; n++)
		{
			printf("%f\t", k[m][n]);
		}
		printf("\n");
	}
}
int main()
{
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<4; j++)
		{
			printf("a[%d][%d]", i, j);
			scanf("%lf", &a[i][j]);
		}
	}
	goster(a);

	//1. satırın ilk satır ve sutunu 1 yapmak
	temp = a[0][0];
	printf("1. satiri %d ile bölelim\n", temp);
	/*
	a[0][0]/=temp;
	a[0][1]/=temp;
	a[0][2]/=temp;
	a[0][3]/=temp;
	*/
	for (int j = 0; j<4; j++)
	{
		a[0][j] /= temp;
	}
	goster(a);
	//2. satırın 1. sütununu sıfırlama işlemi
	temp = a[1][0];
	printf("1. satirin (%d) katini 2. satira ekliyelim\n", temp);
	/*
	a[1][0]+=-temp*a[0][0];
	a[1][1]+=-temp*a[0][1];
	a[1][2]+=-temp*a[0][2];
	a[1][3]+=-temp*a[0][3];
	*/
	for (int j = 0; j<4; j++)
	{
		a[1][j] += -temp*a[0][j];
	}
	goster(a);
	//3. satırın 1. sütununu sıfırlama işlemi
	temp = a[2][0];
	printf("1. satirin (%d) katini 2. satira ekliyelim\n", temp);
	/*
	a[2][0]+=-temp*a[0][0];
	a[2][1]+=-temp*a[0][1];
	a[2][2]+=-temp*a[0][2];
	a[2][3]+=-temp*a[0][3];
	*/
	for (int j = 0; j<4; j++)
	{
		a[2][j] += -temp*a[0][j];
	}
	goster(a);
	//2. satırın ilk satır ve sutunu 1 yapmak
	temp = a[1][1];
	printf("2. satiri %d ile bölelim\n", temp);
	/*
	a[1][0]/=temp;
	a[1][1]/=temp;
	a[1][2]/=temp;
	a[1][3]/=temp;
	*/
	for (int j = 0; j<4; j++)
	{
		a[1][j] /= temp;
	}
	goster(a);
	//3. satırın 2. sütununu sıfırlama işlemi
	temp = a[2][1];
	printf("2. satirin %d katini 3. satira ekliyelim\n", temp);
	/*
	a[2][0]+=-temp*a[1][0];
	a[2][1]+=-temp*a[1][1];
	a[2][2]+=-temp*a[1][2];
	a[2][3]+=-temp*a[1][3];
	*/
	for (int j = 0; j<4; j++)
	{
		a[2][j] += -temp*a[1][j];
	}
	goster(a);
	//3. satırın ilk satır ve sutunu 1 yapmak
	temp = a[2][2];
	/*
	a[2][0]/=temp;
	a[2][1]/=temp;
	a[2][2]/=temp;
	a[2][3]/=temp;
	*/
	for (int j = 0; j<4; j++)
	{
		a[2][j] /= temp;
	}
	goster(a);
	//1. satır 2. sutunu 0 yapmak
	temp = a[0][1];
	/*
	a[0][0]+=-temp*a[1][0];
	a[0][1]+=-temp*a[1][1];
	a[0][2]+=-temp*a[1][2];
	a[0][3]+=-temp*a[1][3];
	*/
	for (int j = 0; j<4; j++)
	{
		a[0][j] += -temp*a[1][j];
	}
	//1.satır 3.sutunu 0 yapmak
	temp = a[0][2];
	/*
	a[0][0]+=-temp*a[2][0];
	a[0][1]+=-temp*a[2][1];
	a[0][2]+=-temp*a[2][2];
	a[0][3]+=-temp*a[2][3];
	*/
	for (int j = 0; j<4; j++)
	{
		a[0][j] += -temp*a[2][j];
	}
	//2.satır 3.sutunu 0 yapmak
	temp = a[1][2];
	/*
	a[1][0]+=-temp*a[2][0];
	a[1][1]+=-temp*a[2][1];
	a[1][2]+=-temp*a[2][2];
	a[1][3]+=-temp*a[2][3];
	*/
	for (int j = 0; j<4; j++)
	{
		a[1][j] += -temp*a[2][j];
	}
	
	goster(a);
	printf("x=%d\ny=%d\nz=%d\n",a[0][0],a[1][1],a[2][2]);
	getch();
	return 0;
}
