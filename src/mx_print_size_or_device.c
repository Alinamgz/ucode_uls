#include "uls.h"

void mx_print_size_or_device(t_forlong *forlong, struct stat forstat, t_flags *f, t_parse *p) {
    if (S_ISCHR(forstat.st_mode) || S_ISBLK(forstat.st_mode)) {
        mx_find_major_minor(forstat.st_rdev, forlong);
        mx_print_lnumber(forlong->major, forlong->max_len[5]);
        mx_printchar(',');
        mx_print_lnumber(forlong->minor, forlong->max_len[6]);
    }
    else if ((!S_ISCHR(forstat.st_mode) || !S_ISBLK(forstat.st_mode)) 
        && forlong->count_of_device_files > 0 && p->count_of_dirs > 0)
        mx_print_lnumber(forstat.st_size, forlong->max_len[3] + forlong->max_len[5] + forlong->max_len[6] + 1);
    else if ((!S_ISCHR(forstat.st_mode) || !S_ISBLK(forstat.st_mode))
        && forlong->count_of_device_files > 0 && p->count_of_dirs < 1)
        mx_print_lnumber(forstat.st_size, forlong->max_len[3] + (forlong->max_len[3] - forlong->max_len[6]) + 1);
        
    else if (f->lg_h) {
        mx_for_flag_h(forlong, forstat.st_size);
        mx_print_lname_right(forlong->suffix_size, forlong->max_len[3]);
        mx_strdel(&forlong->suffix_size);
    }
    else
        mx_print_lnumber(forstat.st_size, forlong->max_len[3]); /////////////////
}
