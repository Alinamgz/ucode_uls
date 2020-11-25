#include "uls.h"

void mx_list_longdir(char *path, t_forlong *forlong, t_parse *p, t_flags *f) {
    forlong = (t_forlong *)malloc(sizeof(t_forlong));
    struct stat forstat;
    struct passwd *foruserid;
    struct group *forgroupid;

    mx_directory_info(p, path, f);
    for (int i = 0; i < p->count_of_objects; i++) {
            lstat(p->content_of_directory[i], &forstat);
            if (i == 0) {
                mx_count_max_len(p, forlong);
                mx_printstr("total ");
                mx_printint(forlong->max_len[4]);
                mx_printchar('\n');
            }
            mx_print_type_of_file(forstat);
            mx_print_file_permissions(forstat);
            mx_check_acl_and_attributes(p->content_of_directory[i]);
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
            mx_print_name_path(p->content_of_directory[i],
                               forstat, p->content_of_directory[i], f->lg_G);

            if (f->lg_x)
                mx_print_xattr(p->content_of_directory[i]);
            if (f->lg_e)
                mx_print_acl(p->content_of_directory[i]);
            mx_printstr("\n");
    }
}
