#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int j = 0;
    int i = 0;

    i = mx_strlen(s1);    
    for (j = 0; s2[j] != '\0'; j++)
        s1[i+j] = s2[j];
    s1[i+j] = '\0';
    return s1;
}
