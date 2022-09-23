#include "../include/a4_main.h"

int main(void) {
    int select_var;

    puts("Welcome To Assignment 4!\n");
    
    while (select_var != 3) {
        puts("Main Menu.");
        puts("1: Exercise_4a");
        puts("2: Exercise_4b");
        puts("3: Close program");
        select_var = get_int_from_user("Please choose option: ",1,3);

        if (select_var == 1) {
            puts("\nExercise_4a:");
            printf("The number of bits in data type int is: %d.\n", bit_counter());
            puts("Returning to Main Menu...\n");
        }

        if (select_var == 2) {
            
            puts("\nExercise_4b:");

        }
    }

    puts("Program closing...");

}
  


