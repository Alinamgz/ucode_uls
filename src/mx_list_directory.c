#include "uls.h"

static void column_output(t_parse *p, char *path, bool flag_G) {
    struct stat forstat;
    char *fullpath = NULL;

    for (int i = 0; i < p->count_of_objects; i++) {
        if (flag_G){
            fullpath = mx_fullpath(path, p->content_of_directory[i]);
            lstat(fullpath, &forstat);
            mx_colorize(forstat);
            mx_printstr(p->content_of_directory[i]);
            mx_printstr(RESET_COLORS);
            mx_strdel(&fullpath);
        }
        else {
            mx_printstr(p->content_of_directory[i]);
        }
        mx_printchar('\n');
    }
}

void mx_list_directory(t_parse *p, char *path, t_flags *f) {
    mx_directory_info(p, path, f);
    if (isatty(1) && !f->lg_1) {
        f->lg_G ? mx_line_output_colorful(p, path) : mx_line_output(p);
    }
    else{
        f->lg_G = isatty(1);
        column_output(p, path, f->lg_G);
    }
    
    p->count_of_objects = 0;
    return;
}
