#include "uls.h"

void mx_print_in_multiline(t_parse *p, int first_ln, struct winsize size_wind, bool flag_G) {
    int count = 0;
    int tabs = 0;
    int num_of_columns = size_wind.ws_col / first_ln;
    int num_of_rows = p->count_of_objects / num_of_columns;
    struct stat forstat;

    if (p->count_of_objects % num_of_columns != 0) {
        num_of_rows++;
    }
    for (int i = 0; i < num_of_rows; i++) {
        for (int j = i; j < p->count_of_objects; j += num_of_rows) {
            if (flag_G){
                lstat(p->content_of_directory[j], &forstat);
                mx_colorize(forstat);
            }
            mx_printstr(p->content_of_directory[j]);
            mx_printstr(RESET_COLORS);
            count = 0;
            count = (first_ln - mx_strlen(p->content_of_directory[j])) / 8;
            if ((first_ln - mx_strlen(p->content_of_directory[j])) % 8 != 0) {
                count++;
            }
            for (tabs = 0; tabs < count; tabs++) {
                mx_printchar('\t');
            }
        }
        mx_printchar('\n');
    }
}
