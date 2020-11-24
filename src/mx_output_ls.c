#include "uls.h"

void mx_output_ls(t_parse *p, char *path, t_flags *f) {
    t_forlong *forlong = NULL;

    if (!p->files && !p->dirs) {
        if (f->lg_l) {
            mx_list_longdir(path, forlong, p, f);
        }
        else {
            mx_list_directory(p, path, f);
        }
    }

    if (p->files || p->dirs) {
        if (f->lg_l) {
            mx_list_few_longdirs(path, forlong, p, f);
        }
        else {
            mx_list_few_filedirs(p, path, f);
        }
    }
}
