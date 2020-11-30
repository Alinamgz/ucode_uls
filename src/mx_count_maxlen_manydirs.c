#include "uls.h"

void mx_count_maxlen_manydirs(t_parse *p, t_forlong *forlong) {
    forlong->max_len = (int *)malloc(sizeof(int) * 7);
    forlong->major = 0;
    forlong->minor = 0;
    forlong->count_of_device_files = 0;
    forlong->major = 0;
    forlong->minor = 0;
    forlong->count_of_device_files = 0;
    forlong->fault_groupid = NULL;
    forlong->fault_userid = NULL;
    struct stat forstat;
    struct passwd *foruserid;
    struct group *forgroupid;
    char *fullpath = NULL;

    for (int j = 0; j < 7; j++)
        forlong->max_len[j] = 0;
    for (int i = 0; i < p->count_of_objects; i++) {
        fullpath = mx_fullpath(p->path_pref, p->content_of_directory[i]);
        lstat(fullpath, &forstat);

        forlong->max_len[4] += forstat.st_blocks;
        if (mx_intlen(forstat.st_nlink) > forlong->max_len[0]) 
            forlong->max_len[0] = mx_intlen(forstat.st_nlink);

        foruserid = getpwuid(forstat.st_uid);
        if (foruserid == NULL) {
            forlong->fault_userid = mx_itoa(forstat.st_uid);
            if (mx_strlen(forlong->fault_userid) > forlong->max_len[1])
                forlong->max_len[1] = mx_strlen(forlong->fault_userid);
            free(forlong->fault_userid);
            forlong->fault_userid = NULL;
        }
        else
            if (mx_strlen(foruserid->pw_name) > forlong->max_len[1])
                forlong->max_len[1] = mx_strlen(foruserid->pw_name);

        forgroupid = getgrgid(forstat.st_gid);
        if (forgroupid == NULL) {
            forlong->fault_groupid = mx_itoa(forstat.st_gid);
            if (mx_strlen(forlong->fault_groupid) > forlong->max_len[2])
                forlong->max_len[2] = mx_strlen(forlong->fault_groupid);
            free(forlong->fault_groupid);
            forlong->fault_groupid = NULL;
        }
        else
            if (mx_strlen(forgroupid->gr_name) > forlong->max_len[2])
                forlong->max_len[2] = mx_strlen(forgroupid->gr_name);

        if (mx_intlen(forstat.st_size) > forlong->max_len[3])
            forlong->max_len[3] = mx_intlen(forstat.st_size);
            
        if (S_ISCHR(forstat.st_mode) || S_ISBLK(forstat.st_mode)) {
                forlong->max_len[5] = 3;
                forlong->max_len[6] = 3;
            forlong->count_of_device_files++;
        }
        free(fullpath);
        fullpath = NULL;
    }
}
