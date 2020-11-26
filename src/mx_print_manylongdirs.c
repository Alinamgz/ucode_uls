#include "uls.h"

void mx_print_manylongdirs(char *path, t_forlong *forlong, t_parse *p, t_flags *f) {
    forlong = (t_forlong *)malloc(sizeof(t_forlong));
    struct stat forstat;
    char *fullpath = NULL;

    mx_directory_info(p, path, f);
    for (int i = 0; i < p->count_of_objects; i++) {
            fullpath = mx_fullpath(path, p->content_of_directory[i]);
            lstat(fullpath, &forstat);
            if (i == 0) {
                mx_count_maxlen_manydirs(path, p, forlong);
                mx_printstr("total ");
                mx_printint(forlong->max_len[4]);
                mx_printchar('\n');
            }
            mx_print_type_of_file(forstat);
            mx_print_file_permissions(forstat);
            mx_check_acl_and_attributes(fullpath);
            mx_print_lnumber(forstat.st_nlink, forlong->max_len[0]);
            mx_print_user_group(forstat, forlong);
            mx_printchar(' ');
            mx_print_size_or_device(forlong, forstat, f, p);
            mx_printchar(' ');
            mx_print_time(forstat, f);
            mx_print_name_path(p->content_of_directory[i],
                               forstat, fullpath, f->lg_G);

            if (f->lg_x)
                mx_print_xattr(fullpath);
            if (f->lg_e)
                mx_print_acl(fullpath);
            mx_printstr("\n");
            free(fullpath);
            fullpath = NULL;
    }
    if (p->content_of_directory)
        for (int i = 0; i < p->count_of_objects; i++)
            free(p->content_of_directory[i]);
    if (p->content_of_directory)
        free(p->content_of_directory);
    p->content_of_directory = NULL; //free
    p->count_of_objects = 0;
    free(forlong->max_len);
    free(forlong);
}
