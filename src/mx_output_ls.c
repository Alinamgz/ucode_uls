#include "uls.h"

void mx_output_ls(t_parse *p, t_flags *f) {
    t_forlong *forlong = NULL;

    if (!p->addresses && !p->nopermis) {
        if (f->lg_l) {
            mx_list_longdir(forlong, p, f);
        }
        else {
            mx_list_directory(p, f);
        }
    }
    if (p->files || p->dirs || p->nopermis) {
        if (f->lg_l) {
            mx_list_few_longdirs(forlong, p, f);
        }
        else {
            mx_list_few_filedirs(p, f);
        }
    }
}
