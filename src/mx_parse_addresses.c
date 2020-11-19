#include "uls.h"

void mx_parse_addresses(int i, int argc, char **argv, t_parse *p) {
	int adr_size = argc - i;
	int j = 0;

	p->addresses = (char**)malloc(sizeof(char*) * (1 + adr_size));
	for (j = 0; argv[i + j]; j++) {
		p->addresses[j] = mx_strdup(argv[i + j]);
	}
	p->addresses[j] = NULL;
	mx_sort_alphabetically(p->addresses, 0, j-1);
	mx_sort_addresses(p, j);
}
