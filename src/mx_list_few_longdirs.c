#include "uls.h"

void mx_list_few_longdirs(t_forlong *forlong, t_parse *p, t_flags *f) {
    if (p->files) {
        mx_list_longfile(forlong, p, f);
        if (p->dirs)
            mx_printchar('\n');
    }

    if (p->dirs)
        for (int i = 0; p->dirs[i]; i++) {
            if (p->count_of_dirs > 1 || p->files || p->invalid) {
                mx_printstr(p->dirs[i]);
                mx_printstr(":\n");
            }
            p->path_pref = p->dirs[i];
            mx_print_manylongdirs(forlong, p, f);
            if (p->dirs[i + 1])
                mx_printchar('\n');
        }
}
