#include "uls.h"

void mx_list_longfile(t_forlong *forlong, t_parse *p, t_flags *f) {
    forlong = (t_forlong *)malloc(sizeof(t_forlong));
    struct stat forstat;
    struct passwd *foruserid;
    struct group *forgroupid;

    for (int i = 0; i < p->count_of_files; i++) {
            mx_count_maxlen_files(p, forlong);
            lstat(p->files[i], &forstat);
            mx_print_type_of_file(forstat);
            mx_print_file_permissions(forstat);
            mx_check_acl_and_attributes(p->files[i]);
            mx_print_lnumber(forstat.st_nlink, forlong->max_len[0]);
            foruserid = getpwuid(forstat.st_uid);
            mx_print_lname(foruserid->pw_name, forlong->max_len[1]);
            mx_printchar(' ');
            forgroupid = getgrgid(forstat.st_gid);
            if (forgroupid == NULL) {
                forlong->fault_groupid = mx_itoa(forstat.st_gid);
                mx_print_lname(forlong->fault_groupid, forlong->max_len[2]);
                free(forlong->fault_groupid);
                forlong->fault_groupid = NULL;
            }
            else
                mx_print_lname(forgroupid->gr_name, forlong->max_len[2]);
            
            mx_printchar(' ');
            mx_print_size_or_device(forlong, forstat, f, p);
            mx_printchar(' ');
            mx_print_time(forstat, f);
            if (f->lg_G)
                mx_colorize(forstat);
            mx_print_name_path(p->files[i], forstat, p->files[i]);
            if (f->lg_x)
                mx_print_xattr(p->files[i]);
            if (f->lg_e)
                mx_print_acl(p->files[i]);
            mx_printstr("\n");
    }
}
