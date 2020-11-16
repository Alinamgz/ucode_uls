#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    int i = left;
    int j = right;
    int medium = (right + left) / 2;
    int swaps = 0;

    if (!arr)
        return -1;
    if (left < right) {
        for ( ; mx_strlen(arr[i]) < mx_strlen(arr[medium]); i++);
        for ( ; mx_strlen(arr[j]) > mx_strlen(arr[medium]); j--);
        if (i < j && mx_strlen(arr[i]) != mx_strlen(arr[j])) {
            custom_swap_char2(arr, i, j);
            swaps++;
        }
        ++i < right ? swaps = swaps + mx_quicksort(arr, i, right) : i;
        --j > left ? swaps = swaps + mx_quicksort(arr, left, j) : j;
    }
    return swaps;
}
