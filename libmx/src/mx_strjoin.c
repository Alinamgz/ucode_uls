#include "libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
    char *result;
    int result_size;

    if (s1 == NULL && s2 == NULL) {
        return NULL;
    }
    else if (s1 == NULL || s2 == NULL) {
        result = s1 ? mx_strdup(s1) : mx_strdup(s2);
    }
    else {
        result_size = mx_strlen(s1) + mx_strlen(s2);
        result = mx_strnew(result_size);
        mx_strcpy(result, s1);
        mx_strcat(result, s2);
    }
    return result;
}
