/*
Student: Mads Richardt, s224948
*/

#include "a3.h"
#include "a3.c"
#include "a3_b.h"
#include "a3_b.c"
#include "a3_a.h"
#include "a3_a.c"

int main(void) {
   int control_var = 0;

   //Print welcome string.
   puts("Welcome to Assignment 3, enjoy... :)\n");

   // Select Exercise.
   while(1) {
      control_var = get_int_from_user("Select exercise (0: Quit, 1: Exercise_A, 2: Exercise_B): ", 0, 2, false);
      switch (control_var)
      {
      case 0:
         puts("Program closing...");
         exit(0);
      case 1:
         puts("\nExercise_A selected:");
         a3_a();
         puts("Closing Exercise_A...");
         break;
      case 2:
         puts("\nExercise_B selected:");
         a3_b();
         puts("Closing Exercise_B...");
         break;
      }
      puts("");
   }
}