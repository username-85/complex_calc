#include "util.h"
#include "oper.h"

struct complex_num{
	double real, img;
};

static bool file_exists(const char *fname);
static void skip_chars(void);

double complex get_complex_num(void) {
	struct complex_num cnum  = {0, 0};

	int ok;
	do {
		printf("Enter real part: ");
		ok = scanf("%lf", &cnum.real);
		skip_chars();
	} while (!ok);

	do {
		printf("Enter imaginary part: ");
		ok = scanf("%lf",&cnum.img);
		skip_chars();
	} while (!ok);

	return (cnum.real + cnum.img * I);
}

static bool file_exists(const char *fname) {
	FILE *file;
	if (( file = fopen(fname, "r") )) {
		fclose(file);
		return 1;
	}
	return 0;
}

int init_oper_signs(char *oper_signs) {
	char *lib_fnames[] = {"./lib/libsum.so", "./lib/libdelta.so", 
	                      "./lib/libmultiplication.so", 
	                      "./lib/libdivision.so", NULL};

	int oper_cnt = 0;
	for (char **p = lib_fnames; *p != NULL; p++) {
		if (file_exists(*p)) {	
			oper_signs[oper_cnt++] = get_oper_sign_for_lib(*p);
		}
	}
	if (oper_cnt) oper_signs[oper_cnt + 1] = 0;

	return oper_cnt;
}

char get_choice(char const *opers, char const quit) {
	char ch;
	do {
		printf("Available operations: %s. "
		       "Enter operation sign or enter %c to quit\n", opers, quit);
		ch = get_first_ch();

	} while ( (!strchr(opers, ch)) && (ch != quit) );
	return ch;
}

char get_first_ch(void) {
	char ch;
	ch = getchar();
	skip_chars();
	return ch;
}


static void skip_chars(void) {
	while (getchar() != '\n') continue;
}
