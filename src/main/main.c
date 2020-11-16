#include "../../inc/uls.h"

int main (int argc, char *argv[]) {
    char current_path[] = ".";
    char *path = current_path;

    if (argc == 1)
        list_directory();
    if (argc > 1 && strcmp(argv[1], "-l") == 0) {
        if (argc > 2)
            for (int i = 2; i < argc; i++) {
                mx_printstr(argv[i]);
                mx_printstr(":\n");
                path = argv[i];
                list_longdir(path);
                    if(i + 1 < argc)
                        mx_printchar('\n');
            }
        else 
            list_longdir(path);
    }
    return 0;
}
