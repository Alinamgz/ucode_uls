#include "uls.h"

void mx_list_longfile(t_forlong *forlong, t_parse *p, t_flags *f) {
    forlong = (t_forlong *)malloc(sizeof(t_forlong));
    struct stat forstat;

    for (int i = 0; i < p->count_of_files; i++) {
        mx_count_maxlen_files(p, forlong);
        lstat(p->files[i], &forstat);
        mx_print_type_of_file(forstat);
        mx_print_file_permissions(forstat);
        mx_check_acl_and_attributes(p->files[i]);
        mx_print_lnumber(forstat.st_nlink, forlong->max_len[0]);
        mx_print_user_group(forstat, forlong);         
        mx_printchar(' ');
        mx_print_size_or_device(forlong, forstat, f);
        mx_printchar(' ');
        mx_print_time(forstat, f);
        mx_print_name_path(p->files[i], forstat, p->files[i], f->lg_G);
        if (f->lg_x)
            mx_print_xattr(p->files[i]);
        if (f->lg_e)
            mx_print_acl(p->files[i]);
        mx_printstr("\n");
        free(forlong->max_len);
    }
    free(forlong);
}
