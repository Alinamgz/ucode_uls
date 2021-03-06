#include "uls.h"

void mx_list_few_filedirs(t_parse *p, char *path, t_flags *f) {
    if (p->files) {
        mx_list_files(p, f->lg_1);
        if (p->dirs)
            mx_printchar('\n');
    }

    if (p->dirs)
        for (int i = 0; p->dirs[i] != NULL; i++) {
            if (p->count_of_dirs > 1) {
                mx_printstr(p->dirs[i]);
                mx_printstr(":\n");
            }
            path = p->dirs[i];
            mx_list_directory(p, path, f);
            if (p->dirs[i + 1] != NULL)
                mx_printchar('\n');
        }
}
