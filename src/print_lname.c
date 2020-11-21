#include "uls.h"

void print_lname(char *name, int max_len) {
    int len = mx_strlen(name);
    int diff = max_len - len;
    char *all_array = mx_strnew(max_len);
    int i = 0;

    for (int j = 0; j < len; j++) {
        all_array[i] = name[j];
        i++;
    }

    if (diff != 0)
        while(i < diff) {
            all_array[i] = ' ';
            i++;
        }
        
    mx_printstr(all_array);
    free(all_array);
}
