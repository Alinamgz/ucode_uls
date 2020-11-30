#include "uls.h"

void mx_print_name_path(char *name_to_print, struct stat forstat,
                        char *fullpath, bool flag_G) {
    int return_value = 0;
    char *sympath = NULL;

    if (S_ISLNK(forstat.st_mode)) {
        sympath = mx_strnew(forstat.st_size);
        return_value = readlink(fullpath, sympath, forstat.st_size);
        mx_printchar(' ');
        if (flag_G && isatty(1)) {
            mx_colorize(forstat);
            mx_printstr(name_to_print);
            mx_printstr(RESET_COLORS);
        }
        else {
            mx_printstr(name_to_print);
        }
        mx_printstr(" -> ");
        if (mx_strcmp(name_to_print, "stderr") == 0 &&
            mx_get_substr_index(fullpath, "/dev/") > -1)
            mx_printstr("fd/2");
        if (mx_strcmp(name_to_print, "stdin") == 0 &&
            mx_get_substr_index(fullpath, "/dev/") > -1)
            mx_printstr("fd/0");
        if (mx_strcmp(name_to_print, "stdout") == 0 &&
            mx_get_substr_index(fullpath, "/dev/") > -1)
            mx_printstr("fd/1");
        mx_printstr(sympath);
        mx_strdel(&sympath);
    }
    else {
        mx_printchar(' ');
        if (flag_G && isatty(1)) {
            mx_colorize(forstat);
            mx_printstr(name_to_print);
            mx_printstr(RESET_COLORS);
        } else {
            mx_printstr(name_to_print);
        }
    }
}
