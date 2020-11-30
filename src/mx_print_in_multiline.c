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

void mx_print_in_multiline(t_parse *p, int first_ln, int max_width,
                           t_flags *f) {
    int count = 0;
    int tabs = 0;
    int num_of_columns = max_width / first_ln;
    int num_of_rows = p->count_of_objects / num_of_columns;

    if (p->count_of_objects % num_of_columns != 0) {
        num_of_rows++;
    }
    for (int i = 0; i < num_of_rows; i++) {
        for (int j = i; j < p->count_of_objects; j += num_of_rows) {
            name_outp(p->path_pref, p->content_of_directory[j], f->lg_G,
                      f->just_files);

            count = 0;
            if (!f->lg_G && isatty(1)) {
                count = (first_ln - mx_strlen(p->content_of_directory[j])) / 8;
                if ((first_ln - mx_strlen(p->content_of_directory[j])) % 8 !=
                    0) {
                    count++;
                }
                if (p->count_of_objects > j + num_of_rows)
                    for (tabs = 0; tabs < count; tabs++) {
                        mx_printchar('\t');
                }
            }
            else {
                count = (first_ln - mx_strlen(p->content_of_directory[j]));
                if (p->count_of_objects > j + num_of_rows)
                    for (tabs = 0; tabs < count; tabs++) {
                        mx_printchar(' ');
                    }
            }
        }
        mx_printchar('\n');
    }
}
             
