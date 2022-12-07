#include "bit_counter.h"

int bit_counter(void) {
    int counter = -1;
    int n_new = 1;
    int n_old = 0;
    while (n_new != n_old) {
        n_old = n_new;
        n_new = 2 * n_old;
        counter++;
    }
    return counter;
}

