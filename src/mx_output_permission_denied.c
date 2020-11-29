#include "uls.h"

static char *file_badaccess(char *address, t_parse *p) {
	int len = mx_strlen(address);
	p->str_nopermis = mx_strnew(len);

	if (mx_get_char_index(address, '/') > -1) {
		for(int i = 0; i < len; i++) {
			if (address[len - i - 1] == '/') {
				mx_str_reverse(p->str_nopermis);
				return p->str_nopermis;
			}
			p->str_nopermis[i] = address[len - i - 1];
		}
	}
	return address;
}

void mx_output_permission_denied(t_parse *p) {
    if (p->nopermis && p->nopermis[0]) {
		for (int i = 0; p->nopermis[i]; i++) {
			if (p->nopermis[i + 1] || p->addresses) {
            	mx_printerr(p->nopermis[i]);
            	mx_printstr(":\n");
			}
            mx_printerr(ULS);
            mx_printerr(file_badaccess(p->nopermis[i], p));
            mx_printerr(DENIED_ERR);
		if (p->nopermis[i + 1] || p->dirs)
			mx_printchar('\n');
	    }
    }
	mx_strdel(&p->str_nopermis);
}
