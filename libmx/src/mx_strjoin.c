#include "libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
    char *p = NULL;
    
    if (s2 == NULL && s1 == NULL) {
        return NULL;
    } 
    else if(s1 == NULL) {
        p = mx_strnew(mx_strlen(s2) + 1);
        p = mx_strcat(p, s2);
    }
    else if (s2 == NULL) {
        p = mx_strnew(mx_strlen(s1) + 1);
        p = mx_strcat(p, s1);
    }
    else {
        p = mx_strnew(mx_strlen((s1) + 1) + mx_strlen((s2) + 1));
        mx_strcpy(p, s1);
        mx_strcat(p, s2);    
    }    
    return p;
}
