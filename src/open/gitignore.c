#include "../../inc/uls.h"

bool gitignore(char *argv[]) {
    char git1[] = ".";
    char git2[] = "..";

    if (*argv == git1 || *argv == git2)
        return false;
    else
        return true;
    
}
