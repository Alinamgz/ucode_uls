#include "uls.h"

void mx_print_in_line(t_parse *p, int first_ln, bool flag_G) {
    int fake_ln = 0;

    for (int i = 0; i < p->count_of_objects; i++) {
        fake_ln = first_ln - mx_strlen(p->content_of_directory[i]);
        struct stat forstat;
        // mx_printstr(p->content_of_directory[i]);

        if (flag_G && isatty(1)) {
            stat(p->content_of_directory[i], &forstat);
            mx_colorize(forstat);
            mx_printstr(p->content_of_directory[i]);
            mx_printstr(RESET_COLORS);
        } else {
            mx_printstr(p->content_of_directory[i]);
        }

        for(int j = 0; j < fake_ln; j++)
            mx_printchar(' ');
    }
    mx_printchar('\n');
}
