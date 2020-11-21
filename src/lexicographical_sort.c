#include "uls.h"

void lexicographical_sort(t_parse *p) {
    char *tmp = NULL;
    int i = 0;
    int j = 0;

    for (i = 0; i < p->count_of_objects; ++i) {
        for (j = i + 1; j < p->count_of_objects; ++j) {
            if (mx_strcmp(p->content_of_directory[i], p->content_of_directory[j]) > 0) {
                tmp = p->content_of_directory[i];
                p->content_of_directory[i] = p->content_of_directory[j];
                p->content_of_directory[j] = tmp;
            }
        }
    }
}
