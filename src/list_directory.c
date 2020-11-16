#include "uls.h"

void list_directory(char *path) {
    struct dirent *de;

    DIR *dr = opendir(path); 
    if (dr == NULL) { 
        mx_printstr("Could not open current directory"); 
        return; 
    } 
    while ((de = readdir(dr)) != NULL) {
            mx_printstr(de->d_name);
            mx_printchar('\t');
        }
    closedir(dr); 
    return;    
}
