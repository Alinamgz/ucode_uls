#include "uls.h"

static inline void name_outp(char *pref, char *name, bool flag_G, bool j_fl) {
    struct stat forstat;
    char *addr = NULL;
    int s_rslt = -1;

    if (flag_G) {
        addr = mx_fullpath(pref, name);

        s_rslt = j_fl ? stat(addr, &forstat) : s_rslt;
        s_rslt == 0 ? s_rslt : lstat(addr, &forstat);
        mx_colorize(forstat);
        mx_printstr(name);
        mx_printstr(RESET_COLORS);
        mx_strdel(&addr);
    }
    else {
        mx_printstr(name);
    }
}

void mx_print_in_line(t_parse *p, int first_ln, t_flags *f) {
    int fake_ln = 0;

    for (int i = 0; i < p->count_of_objects; i++) {
        fake_ln = first_ln - mx_strlen(p->content_of_directory[i]);
        name_outp(p->path_pref, p->content_of_directory[i], f->lg_G,
                  f->just_files);

        if (i + 1 != p->count_of_objects)
            for (int j = 0; j < fake_ln; j++)
                mx_printchar(' ');
    }
    mx_printchar('\n');
}
