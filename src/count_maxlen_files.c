#include "uls.h"

void count_maxlen_files(t_parse *p, t_forlong *forlong) {
    forlong->max_len = (int *)malloc(sizeof(int) * 4);
    struct stat forstat;
    struct passwd *foruserid;
    struct group *forgroupid;

    for (int j = 0; j < 4; j++) {
        forlong->max_len[j] = 0;
    }
    for (int i = 0; i < p->count_of_files; i++) {
        stat(p->files[i], &forstat);
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
    }
}
