#include "uls.h"

void mx_print_lname_right(char *name, int max_len) {
    int len = mx_strlen(name);
    int diff = max_len - len;
    char *all_array = mx_strnew(max_len);
    int i = 0;
    int c = 0;

    if (diff != 0)
        while(c < diff) {
            all_array[i] = ' ';
            i++;
            c++;
    }
    for (int j = 0; j < len; j++) {
        all_array[i] = name[j];
        i++;
    }
    mx_printchar(' ');
    mx_printstr(all_array);
    mx_strdel(&all_array);
}
