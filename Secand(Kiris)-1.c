// mehtayn.com
// Secand(Kiris)-1 Yontemi
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double);

int main()
{
    double p0 = 0.0;
    double p1 = -0.01;
    double p;
    double errorRate = 0.0001;
    int i = 2;
    int N0 = 100;


    printf("%10s%20s%15s\n","Iteration","Approximate Root","Error Rate");
    while(i < N0){
        p = p1 - f(p1) * (p1 - p0) / (f(p1) - f(p0));

        printf("%10d%20.3lf%15.4lf\n",i,p,fabs(p1-p0));

        if(fabs(p-p1) < errorRate){
            printf("Tamamdir.");
            break;
        }

        p0 = p1;
        p1 = p;
        i++;
    }

    return 0;
}

double f(double x)
{
    double result = cos(x) + 2*sin(x) + pow(x,2);

    return result;
}
