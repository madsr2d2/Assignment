#include <stdio.h>

int main() {
    char s1[100]; 
    char s2[100];
    puts("Enter something");
    scanf("%s %s", &s1,&s2);

    printf("%s %s", s1, s2);
}