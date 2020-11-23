#include "uls.h"

void list_longfile(t_forlong *forlong, t_parse *p, t_flags *f) {
    forlong = (t_forlong *)malloc(sizeof(t_forlong));
    struct stat forstat;
    struct passwd *foruserid;
    struct group *forgroupid;

    for (int i = 0; i < p->count_of_files; i++) {
            count_maxlen_files(p, forlong);
            lstat(p->files[i], &forstat);
            mx_print_type_of_file(forstat);
            mx_print_file_permissions(forstat);
            mx_check_acl_and_attributes(p->files[i]);
            print_lnumber(forstat.st_nlink, forlong->max_len[0]);
            foruserid = getpwuid(forstat.st_uid);
            print_lname(foruserid->pw_name, forlong->max_len[1]);
            mx_printchar(' ');
            forgroupid = getgrgid(forstat.st_gid);
            print_lname(forgroupid->gr_name, forlong->max_len[2]);
            mx_printchar(' ');
            print_lnumber(forstat.st_size, forlong->max_len[3]);
            mx_printchar(' ');
            print_time(forstat);
            mx_print_name_path(p->files[i], forstat, p->files[i]);
            mx_printstr("\n");
    }
}
