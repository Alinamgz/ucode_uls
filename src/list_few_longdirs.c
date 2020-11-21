#include "uls.h"

void list_few_longdirs(char *path, t_forlong *forlong, t_parse *p, t_flags *f) {
        list_longfile(forlong, p);

    if (p->dirs)
         mx_printchar('\n');

    if (p->dirs)
        for (int i = 0; p->dirs[i]; i++) {
            mx_printstr(p->dirs[i]);
            mx_printstr(":\n");
            path = p->dirs[i];
            list_longdir(path, forlong, p, f);
            if (p->dirs[i + 1])
                mx_printchar('\n');
        }
}
