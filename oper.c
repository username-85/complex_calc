#include "oper.h"

#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 30

static void 
get_lib_for_oper_sign(char const sign, char *lib_name, int const buffersize);
static void 
get_func_for_oper_sign(char const sign, char *func_name, int const buffersize);

double complex 
oper(char const sign, double complex const a, double complex const b) {
	char func_name[NAME_LENGTH];
	get_func_for_oper_sign(sign, func_name, NAME_LENGTH);
	char lib_name[NAME_LENGTH];
	get_lib_for_oper_sign(sign, lib_name, NAME_LENGTH);

	if (!strlen(lib_name)) {
		fprintf(stderr, "Empty library name\n");
		exit(1);
	}
	if (!strlen(func_name)) {
		fprintf(stderr, "Empty function name\n");
		exit(1);
	}

	char const *error;
	void *handle;
	double complex (*oper_func)(double complex a, double complex b);

	handle = dlopen(lib_name, RTLD_LAZY);
	if (!handle) {
		fprintf(stderr, "Couldn't open %s: %s\n", lib_name, dlerror());
		exit(1);
	}

	dlerror();
	oper_func = dlsym(handle, func_name);
	if ((error = dlerror())) {
		fprintf(stderr, "Couldn't find function %s: %s\n", func_name, error);
		exit(1);
	}

	double complex ret;
	ret = oper_func(a, b);

	dlclose(handle);
	return ret;
}

char get_oper_sign_for_lib(const char *lib_fname) {
	if (strstr(lib_fname, "libsum.so")) return '+';
	else if (strstr(lib_fname, "libdelta.so")) return '-';
	else if (strstr(lib_fname, "libdivision.so")) return '/';
	else if (strstr(lib_fname, "libmultiplication.so")) return '*';

	return 0;
}

void get_lib_for_oper_sign(char const sign, char *lib_name, int const buffersize) {
        if (sign == '+') strncpy(lib_name, "lib/libsum.so", buffersize-1);
        else if (sign == '-') strncpy(lib_name, "lib/libdelta.so", buffersize-1);
        else if (sign == '/') strncpy(lib_name, "lib/libdivision.so", buffersize-1);
        else if (sign == '*') strncpy(lib_name, "lib/libmultiplication.so", buffersize-1);
        lib_name[buffersize] = '\0';
}

void get_func_for_oper_sign(char const sign, char *func_name, int const buffersize) {
        if (sign == '+') strncpy(func_name, "sum", buffersize-1);                                                         
        else if (sign == '-') strncpy(func_name, "delta", buffersize-1);
        else if (sign == '/') strncpy(func_name, "division", buffersize-1);
        else if (sign == '*') strncpy(func_name, "multiplication", buffersize-1);
        func_name[buffersize] = '\0';
}
