#include "uls.h"

static int pull_names (t_direct *direct) {
    struct dirent *de;
    int k = 0;

    direct->content_of_directory = (char **)malloc(sizeof(char *) * direct->count_of_objects + 1); // free
    DIR *dr = opendir(".");
    if (dr == NULL) { 
        mx_printstr("Could not open current directory"); // write in errno format 
        return 0; 
    }
    while ((de = readdir(dr)) != NULL)
        if (de->d_name[0] != '.') {
            direct->content_of_directory[k] = mx_strdup(de->d_name);
            k++;
        }
    closedir(dr);
    return 0;
}

int directory_info(t_direct *direct) {
    struct dirent *de;
    
    DIR *dr = opendir(".");
    if (dr == NULL) { 
        mx_printstr("Could not open current directory"); // write in errno format 
        return 0; 
    }
    while ((de = readdir(dr)) != NULL)
        if (de->d_name[0] != '.')
            direct->count_of_objects++;
    closedir(dr);
    pull_names(direct);
    return 0;
}
