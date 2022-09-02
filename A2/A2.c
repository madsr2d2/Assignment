// Course: Hardware-oriented programming
// Assignment: 1a
// Student name: Mads Richardt
// Date: 26.08.2022
// Description: .....

#include <stdio.h>
int main(void) {
    // Initialize vars.
    int assignment_count = 1, grade = 0, score_sum = 0, score = 0, control_var;
    float average = 0;
    char name[1000];
    char surname[1000]; 
    char s1[] = "Welcome to GradeCalc!\n\n"; 
    char s2[] = "Enter student name (Format: Name Surname): ";
    char s3[] = "Enter score %d: ";
    
    char err1[] = "Error! Grade should be from 0 to 100";
    
    printf("%s", s1);
    
    point2:
    printf("Enter student name (Format: Name Surname): ");
    control_var = scanf("%s %s",&name, &surname);

    while (1) {
        printf("Enter score %d for %s (-1 to go to next student, -2 to quit): ", assignment_count, name);
        scanf("%d", &score);
        
        if (score == -1){
        goto point1;
        }
        if (score == -2) {
            goto point3;

        }

        assignment_count++;
        score_sum += score;
        average = ( (float) score_sum )/(assignment_count - 1);
        
        if (average >= 90) {
            grade = 12;
        }
        if  (average <= 89 && average >= 80) {
            grade = 10;
        } 
        if (average <= 79 && average >= 70) {
            grade = 7;
        }
        if (average <= 69 && average >= 60) {
            grade = 4;
        }
        if (average <= 59 && average >= 40) {
            grade = 2;
        }
        if (average <= 39) {
            grade = 0;
        }

        //printf("Sum: %d, average: %.1f, count: %d",grade_sum,average,assignment_count);
        


    }

    point1:
    printf("Student: %s %s, Student Average: %.1f, Student Grade: %d\n\n",name,surname,average,grade);
    assignment_count = 1;
    score_sum = score = 0;
    goto point2;

    point3:
    printf("%s", "\n\nProgram closed\n");






}
