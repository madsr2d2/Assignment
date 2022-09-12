#include "a3.h"

// Get number from user.
int get_int_from_user(char prompt_str[], int MIN, int MAX) {
    int input, scanned;

    while (1) {
        // Print prompt string.
        printf(prompt_str);
        // Scan for number.
        scanned = scanf("%d", &input);

        // Catch non-numeric input error.
        if (scanned == 0) {
            printf("\nFORMAT ERROR!!! Non-numeric input detected.\n\n");
            clear_stdin();
            continue;
        }

        // Catch out of bounds error.
        if (!(input >= MIN && input <= MAX)) {
            printf("\nFORMAT ERROR!!! Number is out of range.\n\n");
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
    while ((dummy = getchar()) != '\n' && dummy != EOF);
}

