#include "uls.h"

void mx_count_maxlen_files(t_parse *p, t_forlong *forlong) {
    forlong->max_len = (int *)malloc(sizeof(int) * 7); //free
    forlong->major = (int)malloc(sizeof(int));
    forlong->minor = (int)malloc(sizeof(int));
    forlong->count_of_device_files = (int)malloc(sizeof(int));
    forlong->major = 0;
    forlong->minor = 0;
    forlong->count_of_device_files = 0;
    struct stat forstat;
    struct passwd *foruserid;
    struct group *forgroupid;
    
    for (int j = 0; j < 7; j++)
        forlong->max_len[j] = 0;
    for (int i = 0; i < p->count_of_files; i++) {
        lstat(p->files[i], &forstat);
        //forlong->max_len[4] += forstat.st_blocks;
        if (mx_intlen(forstat.st_nlink) > forlong->max_len[0]) 
            forlong->max_len[0] = mx_intlen(forstat.st_nlink);
        foruserid = getpwuid(forstat.st_uid);
        if (mx_strlen(foruserid->pw_name) > forlong->max_len[1])
            forlong->max_len[1] = mx_strlen(foruserid->pw_name);
        forgroupid = getgrgid(forstat.st_gid);
        if (mx_strlen(forgroupid->gr_name) > forlong->max_len[2])
            forlong->max_len[2] = mx_strlen(forgroupid->gr_name);
        if (mx_intlen(forstat.st_size) > forlong->max_len[3])
            forlong->max_len[3] = mx_intlen(forstat.st_size);

        if (S_ISCHR(forstat.st_mode) || S_ISBLK(forstat.st_mode)) {
            //mx_find_major_minor(forstat.st_rdev, forlong);
            //if (mx_intlen(forlong->major) > forlong->max_len[5])
                forlong->max_len[5] = 3;//mx_intlen(forlong->major);
            //if (mx_intlen(forlong->minor) > forlong->max_len[6])
                forlong->max_len[6] = 3;//mx_intlen(forlong->minor);
            forlong->count_of_device_files++;
        }
    }
}
