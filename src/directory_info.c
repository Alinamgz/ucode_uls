#include "uls.h"

static int pull_names (t_parse *p, char *path) {
    struct dirent *de;
    int k = 0;

    p->content_of_directory = (char **)malloc(sizeof(char *) * p->count_of_objects + 1); // free
    DIR *dr = opendir(path);
    if (dr == NULL) { 
        mx_printstr("Could not open current directory"); // write in errno format 
        return 0; 
    }
    while ((de = readdir(dr)) != NULL)
        if (de->d_name[0] != '.') {
            p->content_of_directory[k] = mx_strdup(de->d_name);
            k++;
        }
    lexicographical_sort(p);
    closedir(dr);
    return 0;
}

int directory_info(t_parse *p, char *path) {
    struct dirent *de;
    
    DIR *dr = opendir(path);
    if (dr == NULL) { 
        mx_printstr("Could not open current directory"); // write in errno format 
        return 0; 
    }
    while ((de = readdir(dr)) != NULL)
        if (de->d_name[0] != '.')
            p->count_of_objects++;
    closedir(dr);
    pull_names(p, path);
    return 0;
}
