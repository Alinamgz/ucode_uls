#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    char **new_arr = NULL;

    if (!s)
        return NULL;
    new_arr = (char **)malloc(sizeof(char *) * (mx_count_words(s, c) + 1));
    mx_make_array(s, c, new_arr);
    return new_arr;
}
