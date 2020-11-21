#include "uls.h"

void list_longfile(t_forlong *forlong, t_parse *p) {
    forlong = (t_forlong *)malloc(sizeof(t_forlong));
    struct stat forstat;
    struct passwd *foruserid;
    struct group *forgroupid;
    //directory_info(p, path);
    for (int i = 0; i < p->count_of_files; i++) {
            count_maxlen_files(p, forlong);
            stat(p->files[i], &forstat);

            /*if (i == 0) {
                mx_printstr("total ");
                mx_printint(forlong->max_len[4]);
                mx_printchar('\n');
            }*/

            switch (forstat.st_mode & S_IFMT) {
                case S_IFBLK:  mx_printstr("b"); break;
                case S_IFCHR:  mx_printstr("c"); break; 
                case S_IFDIR:  mx_printstr("d"); break;
                case S_IFIFO:  mx_printstr("p"); break; 
                case S_IFLNK:  mx_printstr("l"); break; 
                case S_IFSOCK: mx_printstr("s"); break;
                default:       mx_printstr("-"); break;
            }
            
            (forstat.st_mode & S_IRUSR) ? mx_printstr("r") : mx_printstr("-");
            (forstat.st_mode & S_IWUSR) ? mx_printstr("w") : mx_printstr("-");
            (forstat.st_mode & S_IXUSR) ? mx_printstr("x") : mx_printstr("-");
            (forstat.st_mode & S_IRGRP) ? mx_printstr("r") : mx_printstr("-");
            (forstat.st_mode & S_IWGRP) ? mx_printstr("w") : mx_printstr("-");
            (forstat.st_mode & S_IXGRP) ? mx_printstr("x") : mx_printstr("-");
            (forstat.st_mode & S_IROTH) ? mx_printstr("r") : mx_printstr("-");
            (forstat.st_mode & S_IWOTH) ? mx_printstr("w") : mx_printstr("-");
            (forstat.st_mode & S_IXOTH) ? mx_printstr("x") : mx_printstr("-");

            mx_get_acl_xattr(p->files[i]);

            mx_printchar(' ');
            print_lnumber(forstat.st_nlink, forlong->max_len[0]);

            mx_printchar(' ');
            foruserid = getpwuid(forstat.st_uid);
            print_lname(foruserid->pw_name, forlong->max_len[1]);

            mx_printchar(' ');
            mx_printchar(' ');
            forgroupid = getgrgid(forstat.st_gid);
            print_lname(forgroupid->gr_name, forlong->max_len[2]);

            mx_printchar(' ');
            mx_printchar(' ');
            print_lnumber(forstat.st_size, forlong->max_len[3]);

            mx_printchar(' ');
            print_time(forstat);
 
            mx_printchar(' ');
            mx_printstr(p->files[i]);
            mx_printstr("\n");
    }
}
