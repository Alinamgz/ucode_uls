#include "uls.h"

void mx_output_invalid_addr(char **invalid) {
	for (int i = 0; invalid[i]; i++) {
		mx_printerr(ULS);
		mx_printerr(invalid[i]);
		mx_printerr(ADDR_ERR);
	}
}
