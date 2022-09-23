#include "../include/a4_main.h"

int main(void) {
    int select_var;

    puts("Welcome To Assignment 4!\n");
    
    while (select_var != 3) {
        puts("Main Menu.");
        puts("1: Exercise_4a");
        puts("2: Exercise_4b");
        puts("3: Exercise_4b_optional");
        puts("4: Close program");
        select_var = get_num_from_usr("Please choose option: ",1,4);

        if (select_var == 1) {
            puts("\nExercise_4a:");
            printf("The number of bits in data type int is: %d.\n", bit_counter());
            puts("Returning to Main Menu...\n");
        }

        if (select_var == 2) {
            double my_float;
            puts("\nExercise_4b:");
            my_float = get_num_from_usr("Enter number: ",-10000000000,10000000000);
            printf("\nSin(%lf) is: %lf",my_float,get_sinx(my_float));


        }
    }

    puts("Program closing...");

}
  


