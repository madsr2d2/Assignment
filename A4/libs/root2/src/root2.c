
#include <math.h>
#include <stdio.h>

double root2(double delta, double number) {
    double root_old = 1;
    double root_est = 0;
    
    
    if (number > 0) {
    }

    while (1) {
        (root_est = 0.5*(root_old + number/root_old));

        if (delta > fabs(root_est-root_old)) {
            break;
        }

        root_old = root_est;
    }
    return root_est;
}