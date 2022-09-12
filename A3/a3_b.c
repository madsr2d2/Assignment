
#include <stdlib.h>
#include <time.h>
#include "a3.h"


// Assignment_3b
void a3_b() {
    // Variable declarations.
    int guess = 0, secrete = 0, counter = 0, lower_limit = 0, upper_limit = 0;
    
    // Seed random number generator with current time.
    srand(time(0));

    while (1) {
        if (counter == 0) {   
            // Get upper and lower bounds from user.
            lower_limit = get_int_from_user("Enter lower bound (Number should be between 0 and 1000): ", 0, 1000);
            upper_limit = get_int_from_user("Enter upper bound (Number should be between 0 and 1000): ", 0, 1000);
            
            while (lower_limit >= upper_limit) {
                printf("\nFORMAT ERROR!!! Upper bound must be larger than lower bound.\n\n");
                upper_limit = get_int_from_user("Enter upper bound (Number should be between 0 and 1000): ", 0, 1000);
            }
            
            // Generate random number.
            printf("Generating secrete number...\n\n");
            secrete = (rand() % (upper_limit - lower_limit + 1) + lower_limit);
        }

        // Get guess.
        guess = get_int_from_user("Enter guess: ", lower_limit, upper_limit);

        // Step counter.
        counter++;

        // If user guessed correct, do this.
        if (guess == secrete) {
            printf("\nCongratulations!!! You guessed the secrete number on attempt %d.\n", counter);

            // Ask user to play again or close program.
            if (get_int_from_user("Enter 1 to play again. Enter 0 to close program: ", 0, 1) == 1) {
                counter = 0;
                puts("");
                continue;
            } 
            else {
                break;
            }
        }

        // If guess is to large, do this.
        if (guess > secrete) {
            printf("\nINCORRECT!!! Your guess is LARGER than the secrete number, try again.\n");
        }
        // If user guess is to low, do this
        else {
            printf("\nINCORRECT!!! Your guess is LOWER than the secrete number, try again.\n");
        }
    }
}