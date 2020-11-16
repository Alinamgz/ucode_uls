#include "../../inc/uls.h"

int list_directory() {
    struct dirent *de;

    DIR *dr = opendir("."); 
    if (dr == NULL) { 
        mx_printstr("Could not open current directory"); 
        return 0; 
    } 
    while ((de = readdir(dr)) != NULL) {
            mx_printstr(de->d_name);
            mx_printchar('\t');
        }
    closedir(dr); 
    return 0;    
}
