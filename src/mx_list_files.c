#include "uls.h"

// static void column_output(t_parse *p, bool flag_G) {
//     struct stat forstat;

//     for (int i = 0; i < p->count_of_objects; i++) {
//         if (flag_G)
//             lstat(p->content_of_directory[i], &forstat);
//             mx_colorize(forstat);
//         mx_printstr(p->content_of_directory[i]);
//         mx_printstr(RESET_COLORS);
//         mx_printchar('\n');
//     }
// }

static void column_output(t_parse *p, int isatty, bool flag_G) {
    struct stat forstat;

    for (int i = 0; i < p->count_of_objects; i++) {
        if (isatty && flag_G){
            lstat(p->content_of_directory[i], &forstat);
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

    // if (isatty(1) && !flag_1) {
    //     line_output(p, flag_G);
    // }
    // else
    //     column_output(p, isatty(1), f->lg_G);

    if (isatty(1) && !f->lg_1) {
        mx_line_output(p, f->lg_G);
    }
    else{
        column_output(p, isatty(1), f->lg_G);
    }

    p->content_of_directory = NULL;
    p->count_of_objects = 0;
    return;
}
