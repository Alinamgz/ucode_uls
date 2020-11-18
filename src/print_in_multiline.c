#include "uls.h"

void print_in_multiline(t_direct *direct, int first_ln, struct winsize size_wind) {
    int count = 0;
    int tabs = 0;
    int num_of_columns = size_wind.ws_col / first_ln;
    int num_of_rows = direct->count_of_objects / num_of_columns;

    if (direct->count_of_objects % num_of_columns != 0) { // test, try to understand why
        num_of_rows++;
    }
    for (int i = 0; i < num_of_rows; i++) {
        for (int j = i; j < direct->count_of_objects; j += num_of_rows) {
            mx_printstr(direct->content_of_directory[j]);
            count = 0;
            count = (first_ln - mx_strlen(direct->content_of_directory[j])) / 8;
            if ((first_ln - mx_strlen(direct->content_of_directory[j])) % 8 != 0) {
                count++;
            }
            for (tabs = 0; tabs < count; tabs++) {
                mx_printchar('\t'); // try to understand why
            }
        }
        mx_printchar('\n');
    }
}
