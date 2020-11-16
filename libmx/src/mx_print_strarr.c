#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    int i = 0;
    
    if (arr && delim) {
        while(arr[i] != NULL) {
            write(1, arr[i], mx_strlen(arr[i]));
            if (arr[i + 1] != NULL)
                write(1, delim, 1);
            i++;
        }
        write(1, "\n", 1);
    }
}
