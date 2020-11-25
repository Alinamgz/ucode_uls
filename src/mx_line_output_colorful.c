#include "uls.h"

void mx_line_output_colorful(t_parse *p, char *path) {
    struct stat forstat;
    char *fullpath = NULL;
mx_printstr("\n ------------- HERE GONNE BE -G MULTICOLUMN ---------- \n");
    for (int i = 0; i < p->count_of_objects; i++) {
        fullpath = mx_fullpath(path, p->content_of_directory[i]);
        lstat(fullpath, &forstat);
        mx_colorize(forstat);
        mx_printstr(p->content_of_directory[i]);
        mx_printstr(RESET_COLORS);
        mx_strdel(&fullpath);
        mx_printchar('\n');
    }
}
