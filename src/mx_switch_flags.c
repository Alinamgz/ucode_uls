#include "uls.h"

void mx_switch_flags(char *flags, t_flags *f) {
	for (int i = 0; flags[i]; i++){
		switch(flags[i]) {
			case 'A':
				f->lg_A = (!f->lg_a && !f->lg_f) ? 1 : 0;
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
			case 'T':
				f->lg_T = 1;
				break;
			case 'h':
				f->lg_h = 1;
				f->lg_T = 0;
				break;
			case '@':
				f->lg_x = 1;
				break;
			case 'e':
				f->lg_e = 1;
				break;
			default:
				break;
		}
	}
}
