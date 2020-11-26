#include "uls.h"

void mx_print_user_group(struct stat forstat, t_forlong *forlong) {
    struct passwd *foruserid;
    struct group *forgroupid;

    foruserid = getpwuid(forstat.st_uid);
    if (foruserid == NULL) {
        forlong->fault_userid = mx_itoa(forstat.st_gid);
        mx_print_lname(forlong->fault_userid, forlong->max_len[2]);
        free(forlong->fault_userid);
        forlong->fault_userid = NULL;
    }
    else
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
}
