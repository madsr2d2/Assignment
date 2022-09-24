#include "../include/num_int1.h"

double num_int1(double (*f)(double), double lim1, double lim2, double delta)
{
    double step = fabs(lim2 -lim1)/delta;
    double sum = 0;
    for (int n=1; n <= delta; n++) 
    {
    sum = sum + (*f)(lim1 + n * step) * step;
    }

    return sum;
}