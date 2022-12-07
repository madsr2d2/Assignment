#include "root2.h"
#include <math.h>
#include <stdio.h>

double root2(double delta, double number) {
    double root_old = 1;
    double root_est = 0;

    while (delta < fabs(root_est - root_old)) {
        (root_est = 0.5*(root_old + number/root_old));
        root_old = root_est;
    }
    return root_est;
}