#ifndef OPER_H 
#define OPER_H

#include <complex.h>

double complex 
oper(char const sign, double complex const a, double complex const b);

char get_oper_sign_for_lib(const char *lib_fname);

#endif 
