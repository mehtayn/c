// mehtayn.com
//Kod Örnekleri

#include <stdio.h>
#include <conio.h>
float a[2][2],a1[2][2],a2[2][2];
float b[2];
float det(float m[2][2])
{
	return m[0][0]* m[1][1]- (m[1][0]* m[0][1]);
}
int main()
{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			printf("a[%d][%d]=",i,j);
			scanf("%f",&a[i][j]);
			a1[i][j]=a[i][j];
			a2[i][j]=a[i][j];
		}
	}
	for(int k=0;k<2;k++)
	{
		printf("b[%d]=",k);
		scanf("%f",&b[k]);
	}
	for(int l=0;l<2;l++)
	{
		a1[l][0]=b[l];
		a2[l][1]=b[l];
	}
	printf("x=%f",det(a1)/det(a));
	printf("y=%f",det(a2)/det(a));
	
	getch();
	return 0;
}
