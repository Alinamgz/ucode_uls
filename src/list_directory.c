#include "uls.h"

static void column_output(t_direct *direct) {
    for (int i = 0; i < direct->count_of_objects; i++) {
        mx_printstr(direct->content_of_directory[i]);
        mx_printchar('\n');
    }
}

void list_directory(t_direct *direct) {
    lexicographical_sort(direct);
    if (isatty(1))
        line_output(direct);
    else
        column_output(direct);
    return;
}
