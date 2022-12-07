
#include "get_float_from_user.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Get number from user.
float get_float_from_user(char prompt_str[], long MIN, long MAX, bool close_on_input_error) {
    int scanned;
    float input; 

    while (1) {
        // Print prompt string.
        printf(prompt_str);
        // Scan for number.
        scanned = scanf("%f", &input);

       
        // Catch non-numeric input error.
        if (scanned == 0) {
            printf("\nFORMAT ERROR!!! Non-numeric input detected.\n\n");
            // If close_on_input_error is true, close program.
            if (close_on_input_error == true) {
                puts("Program closing...");
                exit(1);
            }
            clear_stdin();
            continue;
        }

        // Catch out of bounds error.
        if (!(input >= MIN && input <= MAX)) {
            printf("\nFORMAT ERROR!!! Number is out of range.\n\n");
            // If close_on_input_error is true, close program.
            if (close_on_input_error == true){
                puts("Program closing...");
                exit(1);
            }
            clear_stdin();
            continue;
        }
        break;
    }
    return input;
}


// clear standard inout buffer.
void clear_stdin(void) {
    char dummy;
    while ((dummy = getchar()) != '\n');
}

