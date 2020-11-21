#include "uls.h"

void list_few_filedirs(t_parse *p, char *path, t_flags *f) {
    if (p->files) {
        list_files(p);
        if (p->dirs)
            mx_printchar('\n');
    }

    if (p->dirs)
        for (int i = 0; p->dirs[i] != NULL; i++) {
            mx_printstr(p->dirs[i]);
            mx_printstr(":\n");
            path = p->dirs[i];
            
            list_directory(p, path, f);
            if (p->dirs[i + 1] != NULL)
                mx_printchar('\n');
        }
}
