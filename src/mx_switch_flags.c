#include "uls.h"

void mx_switch_flags(char *flags, t_flags *f) {
	for (int i = 0; flags[i]; i++){
		switch(flags[i]) {
			case 'A':
				if (mx_get_char_index(flags, 'a') < 0)
					f->lg_A = 1;
				break;
			case 'a':
				f->lg_a = 1;
				break;
			case 'l':
				f->lg_l = 1;
				break;
			case 'r':
				f->lg_r = 1;
				break;
			default:
				break;
		}
	}
}
