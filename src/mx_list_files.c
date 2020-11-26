#include "uls.h"

static void column_output(t_parse *p, bool flag_G) {
    struct stat forstat;
    int s_rslt = -1;

    for (int i = 0; i < p->count_of_objects; i++) {
        if (flag_G){
            s_rslt = stat(p->content_of_directory[i], &forstat);
            s_rslt == 0 ? s_rslt : lstat(p->content_of_directory[i], &forstat);
            mx_colorize(forstat);
            mx_printstr(p->content_of_directory[i]);
            mx_printstr(RESET_COLORS);
        }
        else {
            mx_printstr(p->content_of_directory[i]);

        }
        mx_printchar('\n');
    }
}

void mx_list_files(t_parse *p, t_flags *f) {
    p->content_of_directory = p->files;
    p->count_of_objects = p->count_of_files;

    if (isatty(1) && !f->lg_1) {
        mx_line_output(p);
    }
    else{
        f->lg_G = isatty(1);
        column_output(p, f->lg_G);
    }
    //if (p->content_of_directory)
        //free(p->content_of_directory);
    p->content_of_directory = NULL;
    p->count_of_objects = 0;
    return;
}
