#include "uls.h"

static int pull_names (t_parse *p, char *path, t_flags *f) {
    struct dirent *de;
    int k = 0;

    p->content_of_directory = (char **)malloc(sizeof(char *) * p->count_of_objects + 1); // free
    DIR *dr = opendir(path);
    if (dr == NULL) { 
        strerror(errno); 
        return 0; 
    }
    
    if (f->lg_A) {
        while ((de = readdir(dr)) != NULL)
            if (mx_strcmp(de->d_name, ".") && mx_strcmp(de->d_name, ".."))
                p->content_of_directory[k++] = mx_strdup(de->d_name);
        }
    else if (f->lg_a) {
        while ((de = readdir(dr)) != NULL)
                p->content_of_directory[k++] = mx_strdup(de->d_name);
        }
    else {
        while ((de = readdir(dr)) != NULL) {
            if (de->d_name[0] != '.')
                p->content_of_directory[k++] = mx_strdup(de->d_name);
        }
    }
    if (!f->lg_f)
        mx_sort_alphabetically(p->content_of_directory, 0,
                               p->count_of_objects - 1, f->lg_r);
    closedir(dr);
    return 0;
}

int mx_directory_info(t_parse *p, char *path, t_flags *f) {
    struct dirent *de;
   
    DIR *dr = opendir(path);
    if (dr == NULL) { 
        strerror(errno);
        return 0; 
    }

    if (f->lg_A) {
        while ((de = readdir(dr)) != NULL)
            if (mx_strcmp(de->d_name, ".") && mx_strcmp(de->d_name, ".."))
                p->count_of_objects++;
    }
    else if (f->lg_a) {
        while ((de = readdir(dr)) != NULL)
                p->count_of_objects++;
    }
    else {
        while ((de = readdir(dr)) != NULL)
            if (de->d_name[0] != '.')
                p->count_of_objects++;
    }
    closedir(dr);
    pull_names(p, path, f);
    return 0;
}
