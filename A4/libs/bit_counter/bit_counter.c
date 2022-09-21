
#include <stdio.h>

int bit_counter(void) {
    int select_var = 0;
    int counter = 0;

    
    printf("Select data type (1: int, 2: long): ");
    scanf("%d",&select_var);


    switch (select_var) {
        case 1: {
            int n_new = 0;
            int n_old = 1;
            while (1) {
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
    
        case 2: {
            long n_new = 0;
            long n_old = 1;
            while (1) {
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
    }
}