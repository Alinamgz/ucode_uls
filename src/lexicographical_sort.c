#include "uls.h"

void lexicographical_sort(t_direct *direct) {
    char *tmp = NULL;
    int i = 0;
    int j = 0;

    for (i = 0; i < direct->count_of_objects; ++i) {
        for (j = i + 1; j < direct->count_of_objects; ++j) {
            if (mx_strcmp(direct->content_of_directory[i], direct->content_of_directory[j]) > 0) {
                tmp = direct->content_of_directory[i];
                direct->content_of_directory[i] = direct->content_of_directory[j];
                direct->content_of_directory[j] = tmp;
            }
        }
    }
}
