#include "uls.h"

void mx_print_lnumber(int value, int max_len) {
    int len = mx_intlen(value);
    int diff = max_len - len;
    char *all_array = mx_strnew(max_len);
    char *numb_array = mx_itoa(value);
    int i = 0;

    if (diff != 0)
        while(i < diff) {
            all_array[i] = ' ';
            i++;
        }
    for (int j = 0; j < len; j++) {
        all_array[i] = numb_array[j];
        i++;
    }
    mx_printchar(' ');
    mx_printstr(all_array);
    free(all_array);
    free(numb_array);
}
