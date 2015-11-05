// mehtayn.com
//Newton Raphson Methodu 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

using namespace std;

const double pi=3.141592;

double F(double a){
    return log(2*a+2) + sin(5*a-pi);
}
double F_turev(double b){
    return (2/(2*b+2)+5*cos(5*b-pi));
}

int main()
{
    double p, p0, error, tol;
    tol=0.0001;

    int n, i;

    printf("Max Iterasyon sayisini giriniz\n");
    scanf("%d",&n);

    printf("Hata toleransini giriniz\n");
    scanf("%lf",&tol);

    printf("Baslangic noktasini giriniz\n");
    scanf("%lf",&p0);


    for(i=0; i<n; i++){
         p=p0-(F(p0)/F_turev(p0));
        error=fabs(p-p0);

        if(error<tol){
            printf("%d. iterasyonda bulunan kok: %lf ve hata: %lf bulunmustur", i, p, error);
            getch();
            return 0;
        }
        p0=p;

        printf("%d. iterasyonda kok: %lf, hata: %lf\n", i, p, error);
    }
    printf("%d. iterasyon sonucu kok bulunamamistir\n", n);

    return 0;
}
