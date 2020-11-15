#include "libmx.h"

char *mx_concat_words(char **words) {
    char *result = "";
    char *step;

    if (words == NULL)
        return NULL;

    for (int i = 0; words[i] != NULL; i++) {
        if (i == 0)
            step = mx_strdup(words[i]);
        else {
            step = mx_strjoin(result, " ");
            mx_strdel(&result);

            result = mx_strjoin(result, step);
            mx_strdel(&step);

            step = mx_strjoin(result, words[i]);
            mx_strdel(&result);
        }
        result = mx_strjoin(result, step);
        mx_strdel(&step);
    }
    return result;
}
