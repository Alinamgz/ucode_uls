#include "uls.h"

void output_ls(t_parse *p, char *path, t_flags *f) {
    t_forlong *forlong = NULL;

    if (p->flags[0] != '\0' && (!p->files && !p->dirs)) {
        if (mx_get_char_index(p->flags, 'l') >= 0)
            list_longdir(path, forlong, p, f);
    }
    if (p->flags[0] == '\0' && (p->files || p->dirs)) {
        list_few_filedirs(p, path, f);
    }
    else if (p->flags && (p->files || p->dirs))
        list_few_longdirs(path, forlong, p, f);      
}
