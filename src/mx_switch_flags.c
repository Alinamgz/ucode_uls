#include "uls.h"

void mx_switch_flags(char *flags, t_flags *f) {
	for (int i = 0; flags[i]; i++){
		switch(flags[i]) {
			case 'A':
				if (!f->lg_a && !f->lg_f)
					f->lg_A = 1;
				break;
			case 'G':
				f->lg_G = 1;
				break;
			case 'a':
				f->lg_a = 1;
				f->lg_A = 0;
				break;
			case 'f':
				f->lg_f = 1;
				f->lg_A = 0;
				f->lg_a = 1;
				f->lg_r = 0;
				break;
			case 'l':
				f->lg_l = 1;
				f->lg_1 = 0;
				break;
			case 'r':
				f->lg_r = 1;
				break;
			case '1':
					f->lg_1 = 1;
					f->lg_l = 0;
				break;
			default:
				break;
		}
	}
}
