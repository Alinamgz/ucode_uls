#include "uls.h"

void mx_print_file_permissions(struct stat forstat) {
    (forstat.st_mode & S_IRUSR) ? mx_printstr("r") : mx_printstr("-");
    (forstat.st_mode & S_IWUSR) ? mx_printstr("w") : mx_printstr("-");
    if (forstat.st_mode & S_ISUID) {
        mx_printstr("s");
    }
    else if (forstat.st_mode & S_IXUSR) {
        mx_printstr("x");
    }
    else {
        mx_printstr("-");
    }

    (forstat.st_mode & S_IRGRP) ? mx_printstr("r") : mx_printstr("-");
    (forstat.st_mode & S_IWGRP) ? mx_printstr("w") : mx_printstr("-");
    if (forstat.st_mode & S_ISGID) {
        mx_printstr("s");
    }
    else if (forstat.st_mode & S_IXGRP) {
        mx_printstr("x");
    }
    else {
        mx_printstr("-");
    }

    (forstat.st_mode & S_IROTH) ? mx_printstr("r") : mx_printstr("-");
    (forstat.st_mode & S_IWOTH) ? mx_printstr("w") : mx_printstr("-");
    (forstat.st_mode & S_IXOTH) ? mx_printstr("x") : mx_printstr("-");
}
