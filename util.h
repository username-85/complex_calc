#ifndef UTIL_H 
#define UTIL_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <complex.h>

int init_oper_signs(char *oper_signs);
double complex get_complex_num(void);
char get_first_ch(void);
char get_choice(char const *opers, char const quit);

#endif 
