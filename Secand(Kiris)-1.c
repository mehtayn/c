// mehtayn.com
//Secand(Kiris)-1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>


const double pi=3.141592;

double F(double p){
    return cos(p)+2*sin(p)+p*p;
}

int main()
{
    double p, p0, p1, error, tol;
    tol=0.0001;

    int n, i;

    printf("Max Iterasyon sayisini giriniz\n");
    scanf("%d",&n);

    printf("Hata toleransini giriniz\n");
    scanf("%lf",&tol);

    printf("Baslangic noktasini giriniz\n");
    scanf("%lf",&p0);


    for(i=0; i<n; i++){
        p=p1-F(p1)*((p1-p0)/F(p1)-F(p0));
        error=fabs(p-p0);

        if(error<tol){
            printf("%d. iterasyonda bulunan kok: %lf, ve hata: %lf bulunmustur", i, p, error);
            getch();
            return 0;
        }
        p0=p;

        printf("%d. iterasyonda kok: %lf, hata: %lf\n", i, p, error);
    }
    printf("%d. iterasyon sonucu kok bulunamamistir\n", n);

    return 0;
}
