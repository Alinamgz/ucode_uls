#include "uls.h"

void print_in_line(t_direct *direct, int first_ln) {
    int fake_ln = 0;

    for (int i = 0; i < direct->count_of_objects; i++) {
        fake_ln = first_ln - mx_strlen(direct->content_of_directory[i]);
        mx_printstr(direct->content_of_directory[i]);
            for(int j = 0; j < fake_ln; j++)
                mx_printchar(' ');
    }
    mx_printchar('\n');
}
