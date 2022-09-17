
// Get number from user.
int get_int_from_user(char prompt_str[], long MIN, long MAX, bool close_on_input_error) {
    int input, scanned;

    while (1) {
        // Print prompt string.
        printf(prompt_str);
        // Scan for number.
        scanned = scanf("%d", &input);

       
        // Catch non-numeric input error.
        if (scanned == 0) {
            printf("\nFORMAT ERROR!!! Non-numeric input detected.\n\n");
            // If close_on_input_error is true, close program.
            if (close_on_input_error == true) {
                puts("Program closing...");
                exit(0);
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
                exit(0);
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


// Sum numbers from x to y.
int sum_range(long x, long y) {
    
    long sum = 0;

    if (y > x) {
        for (long n = x; n <= y; n++) {
            sum += n;
        }
        return sum;
    } 
    
    if (x > y) {
        for (long n = y; n <= x; n++) {
            sum += n;
        }
        return sum;
    } 
    else {
        return 0;
    }
}


//Get random number from range
int get_random_number_from_range(long x, long y) {
    long random;
    return (rand() % abs(x - y)) + (x < y ? x : y) + 1;
}