#include "libmx.h"

void custom_swap_char2(char **arr, int i, int j) {
    char *p = NULL;

    p = arr[i];
    arr[i] = arr[j];
    arr[j] = p;
}
