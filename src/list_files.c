#include "uls.h"

static void column_output(t_parse *p) {
    for (int i = 0; i < p->count_of_objects; i++) {
        mx_printstr(p->content_of_directory[i]);
        mx_printchar('\n');
    }
}

void list_files(t_parse *p, bool flag_1) {
    p->content_of_directory = p->files;
    p->count_of_objects = p->count_of_files;

    if (isatty(1) && !flag_1) {
        line_output(p);
    }
    else
        column_output(p);
        
    p->content_of_directory = NULL;
    p->count_of_objects = 0;
    return;
}
