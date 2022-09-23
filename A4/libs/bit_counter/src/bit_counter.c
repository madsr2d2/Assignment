#include "../include/bit_counter.h"

int bit_counter(void) {
    int counter = 0;
    int n_new = 0;
    int n_old = 1;
    while (1)
    {
        n_new = 2 * n_old;
        counter++;
        if (n_new == n_old)
        {
            counter--;
            return counter;
        }
        n_old = n_new;
    }
}