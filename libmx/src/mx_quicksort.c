#include "libmx.h"

static void swap_str(char **arr, int si_1, int si_2, int *cnt) {
    char *tmp = arr[si_1];

    arr[si_1] = arr[si_2];
    arr[si_2] = tmp;

    *cnt += 1;
}

int mx_quicksort(char **arr, int left, int right) {
    int rslt = arr ? 0 : -1;
    int p = left + (right - left) / 2;
    int i = left;
    int j = right;

    if (arr && left < right) {
        while (mx_strlen(arr[i]) < mx_strlen(arr[p])) {
            i++;
        }
        while (mx_strlen(arr[j]) > mx_strlen(arr[p])) {
            j--;
        }

        if (i < j && mx_strlen(arr[i]) != mx_strlen(arr[j])) {
            swap_str(arr, i, j, &rslt);
        }
        ++i < right ? rslt += mx_quicksort(arr, i, right) : i;
        --j > left ? rslt += mx_quicksort(arr, left, j) : j;
    }
    return rslt;
}
