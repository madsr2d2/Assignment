
#ifndef GET_INT_FROM_USR_H
#define GET_INT_FROM_USR_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SAFE_MODE false


int get_int_from_user(char[], long, long);
void clear_stdin(void);

#endif