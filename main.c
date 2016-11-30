#include "util.h"
#include "oper.h"

#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <complex.h>

#define MAX_OPER_NUM 4 // +,-,/,*

int main(void) {
	char choice;
	char opers[MAX_OPER_NUM + 1] = {0};

	init_oper_signs(opers);
	if (!strlen(opers)) {
		fprintf(stderr, "There is no libraries in ./lib directory.\n");
		exit(1);
	}

	printf("Complex number calc.\n");
	double complex a, b, ret;
	while (1) {
		choice = get_choice(opers, 'q');
		if (choice == 'q') break;

		printf("Enter first complex number\n");
		a = get_complex_num();

		printf("Enter second complex number\n");
		b = get_complex_num();

		ret = oper(choice, a, b);

		printf("(%.2f + %.2fi) %c (%.2f + %.2fi)", 
		       crealf(a), cimagf(a), choice, crealf(b), cimagf(b));
		printf(" = %.2f + %.2fi\n", crealf(ret), cimagf(ret));
		printf("\n");
	}

	return 0;
}
