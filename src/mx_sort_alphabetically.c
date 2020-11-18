#include "uls.h"

static inline void swap_str(char **arr, int si_1, int si_2) {
    char *tmp = arr[si_1];

    arr[si_1] = arr[si_2];
    arr[si_2] = tmp;
}

void mx_sort_alphabetically(char **arr, int left, int right) {
    int p = left + (right - left) / 2;
    int i = left;
    int j = right;

    if (arr && left < right) {
		
        while (mx_strcmp(arr[i], arr[p]) < 0) {
            i++;
        }
				
        while (mx_strcmp(arr[j], arr[p]) > 0) {
            j--;
        }

        if (i < j && mx_strcmp(arr[j], arr[p]) != 0) {
            swap_str(arr, i, j);
        }

        if (++i < right)
            mx_sort_alphabetically(arr, i, right);

        if (--j > left)
            mx_sort_alphabetically(arr, left, j);
    }
}
