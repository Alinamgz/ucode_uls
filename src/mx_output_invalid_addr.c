#include "uls.h"

void mx_output_invalid_addr(t_parse *p) {
	if (p->invalid != NULL)
		if (p->invalid[0]) {
			for (int i = 0; p->invalid[i]; i++) {
				mx_printerr(ULS);
				mx_printerr(p->invalid[i]);
				mx_printerr(ADDR_ERR);
			if (p->invalid[i + 1] || p->nopermis || p->dirs || p->files)
				mx_printchar('\n');
			}
		}
	if (!p->addresses)
		mx_output_permission_denied(p);
}
