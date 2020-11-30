#include "uls.h"

void mx_print_type_of_file(struct stat forstat) {
     switch (forstat.st_mode & S_IFMT) {
            case S_IFBLK:  mx_printstr("b"); break;
            case S_IFCHR:  mx_printstr("c"); break; 
            case S_IFDIR:  mx_printstr("d"); break;
            case S_IFIFO:  mx_printstr("p"); break; 
            case S_IFLNK:  mx_printstr("l"); break; 
            case S_IFSOCK: mx_printstr("s"); break;
            default:       mx_printstr("-"); break;
    }
}
