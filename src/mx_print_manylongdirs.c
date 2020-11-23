#include "uls.h"

void mx_print_manylongdirs(char *path, t_forlong *forlong, t_parse *p, t_flags *f) {
    forlong = (t_forlong *)malloc(sizeof(t_forlong));
    struct stat forstat;
    struct passwd *foruserid;
    struct group *forgroupid;
    char *fullpath = NULL;
    
    directory_info(p, path, f);
    for (int i = 0; i < p->count_of_objects; i++) {
            fullpath = mx_fullpath(path, p->content_of_directory[i]);
            lstat(fullpath, &forstat);
            if (i == 0) {
                count_maxlen_manydirs(path, p, forlong);
                mx_printstr("total ");
                mx_printint(forlong->max_len[4]);
                mx_printchar('\n');
            }
            mx_print_type_of_file(forstat);
            mx_print_file_permissions(forstat);
            mx_check_acl_and_attributes(fullpath);
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
            if (f->lg_G)
                mx_colorize(forstat);
            mx_print_name_path(p->content_of_directory[i], forstat, fullpath);
            //mx_printstr(RESET);
            mx_printstr("\n");
            free(fullpath);
            fullpath = NULL;
    }
}
