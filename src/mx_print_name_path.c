#include "uls.h"

void mx_print_name_path(char *name_to_print, struct stat forstat, char *fullpath) {
    int return_value = 0;
    char *sympath = mx_strnew(forstat.st_size);
    
     if (S_ISLNK(forstat.st_mode)) {
          return_value = readlink(fullpath, sympath, forstat.st_size);
          mx_printchar(' ');
          mx_printstr(name_to_print);
          // TODO: -G is not srdout
          mx_printstr(RESET_COLORS);
          mx_printstr(" -> ");
          if (mx_strcmp(name_to_print, "stderr") == 0 && mx_get_substr_index(fullpath, "/dev/") > -1)
               mx_printstr("fd/2");   
          if (mx_strcmp(name_to_print, "stdin" ) == 0 && mx_get_substr_index(fullpath, "/dev/") > -1)
               mx_printstr("fd/0");    
          if (mx_strcmp(name_to_print, "stdout") == 0 && mx_get_substr_index(fullpath, "/dev/") > -1)
               mx_printstr("fd/1");
          mx_printstr(sympath);
          free(sympath);
    }
    else {
     mx_printchar(' ');
     mx_printstr(name_to_print);
    }
}
