#include "uls.h"

int output_ls(t_parse *p) {
    char current_path[] = ".";
    char *path = current_path;

    if (p->flags && p->addresses[0] == NULL) {
        if (mx_get_char_index(p->flags, 'l') >= 0)
            list_longdir(path);
    }
    if (p->flags == NULL && p->addresses[0]) {
        for (int i = 1; p->addresses[i][0] != '\0'; i++) {
            mx_printstr(p->addresses[i]);
            mx_printstr(":\n");
            path = p->addresses[i];
            list_directory(path);
            if (p->addresses[i + 1][0] != '\0')
                mx_printchar('\n');
        }
    }
    else if (p->flags && p->addresses[0])
        for (int i = 0; p->addresses[i][0] != '\0'; i++) {
                mx_printstr(p->addresses[i]);
                mx_printstr(":\n");
                path = p->addresses[i];
                list_longdir(path);
                if (p->addresses[i + 1][0] != '\0')
                    mx_printchar('\n');
            }
    return 0;
}
