#include "uls.h"

void mx_parse_addresses(int i, int argc, char **argv, t_parse *p, t_flags *f) {
	int adr_size = argc - i;
	int k = 0;
	int j = 0;
	int l = 0;
	DIR *dr;

	for (j = 0; argv[i + j]; j++) {
		dr = opendir(argv[i + j]);
		if (errno == 13) {
			if (k == 0)
				p->nopermis = (char**)malloc(sizeof(char*) * (1 + adr_size));
			p->nopermis[k] = mx_strdup(argv[i + j]);
			p->nopermis[k + 1] = NULL;
			errno = 0;
			k++;
		}
		else {
			if (dr != NULL)
  				closedir(dr);
			if (l == 0)
				p->addresses = (char**)malloc(sizeof(char*) * (1 + adr_size));
			p->addresses[l] = mx_strdup(argv[i + j]);
			l++;
			p->addresses[l] = NULL;
		}
	}
		
	if (p->addresses)
		mx_sort_addresses(p, f, j);
}
