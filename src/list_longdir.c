#include "uls.h"

int list_longdir(const char *path) {
    DIR *dr;
    struct dirent *fl;
    struct stat forstat;
    struct passwd *foruserid;
    struct group *forgroupid;
    char buf[512];

    dr = opendir(path);
    while((fl = readdir(dr)) != NULL) {   
        mx_strcpy(buf, fl->d_name);
        stat(buf, &forstat);

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

        mx_printchar(' ');
        mx_printint(forstat.st_nlink);

        mx_printchar(' ');
        foruserid = getpwuid(forstat.st_uid);
        mx_printstr(foruserid->pw_name);

        mx_printchar(' ');
        forgroupid = getgrgid(forstat.st_gid);
        mx_printstr(forgroupid->gr_name);

        mx_printchar(' ');
        mx_printint(forstat.st_size);

        mx_printchar(' ');
        mx_printstr(ctime(&forstat.st_mtime));

        //mx_printchar(' ');
        //mx_printstr(fl->d_name);
    }
    closedir(dr);
    return 0;
}
