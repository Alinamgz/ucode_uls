#include "uls.h"

void mx_print_name_path(char *name_to_print, struct stat forstat, char *fullpath) {
    int return_value = 0;
    char *sympath = mx_strnew(forstat.st_size);
    
    mx_printchar(' ');
    mx_printstr(name_to_print);
    mx_printstr(RESET_COLORS);
    if (S_ISLNK(forstat.st_mode)) {
        return_value = readlink(fullpath, sympath, forstat.st_size);
        mx_printstr(" -> ");
        mx_printstr(sympath);
        free(sympath);
    }
}
