#include "../include/num_int1.h"

double num_int1(double (*f)(double), double lim1, double lim2, int delta)
{

    double step = fabs(lim1-lim2)/delta;
    double sum = 0;

    
    for (int n=0; n < delta; n++) {
        sum = sum + (*f)(n*step)*step;       
    }


    return sum;
}