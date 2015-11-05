// mehtayn.com
//Newton Raphson Methodu 2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double f(double);
double fDerivative(double);

int main()
{
    double p0 = 0.0;
    double p;
    double errorRate = 0.0002;
    int i = 0;
    int N0 = 100;


    printf("%10s%20s%15s\n","Iteration","Approximate Root","Error Rate");
    while(i < N0){
        p = p0 - f(p0)/fDerivative(p0);

        printf("%10d%20.4lf%15.4lf\n",i,p,fabs(p-p0));

        if(fabs(p-p0) < errorRate){
            printf("Tamamdir.");
            break;
        }

        p0 = p;
        i++;
    }

    return 0;
}

double f(double x)
{
    double result = 3*x + sin(x) - exp(x);

    return result;
}

double fDerivative(double x)
{
    double result = 3 + cos(x) - exp(x);

    return result;
}
