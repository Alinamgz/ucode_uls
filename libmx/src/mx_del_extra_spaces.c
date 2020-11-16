#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *trimmed = NULL;
    char *final_str = NULL;
    int size;

    if (str == NULL)
        return NULL;
    trimmed = mx_strtrim(str);
    size = mx_strlen(trimmed);
    final_str = mx_strnew(size);
    mx_spacedel(final_str, trimmed);  
    return final_str;   
    mx_strdel(&trimmed); 
    mx_strdel(&final_str); 
}
