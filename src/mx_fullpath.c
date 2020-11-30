#include "uls.h"

char *mx_fullpath(char *path, char *content) {
    int i = 0;
    char *fullpath = mx_strnew(mx_strlen(path) + mx_strlen(content) + 2);

    for ( ; i < mx_strlen(path); i++)
        fullpath[i] = path[i];
        
    if (fullpath[i - 1] != '/')
        fullpath[i] = '/';
    else
        i--;
    
    for (int j = 0; j < mx_strlen(content); j++) {
        i++;
        fullpath[i] = content[j];
    }
    return fullpath;
}
