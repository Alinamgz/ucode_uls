#include "uls.h"

static void swapstr(char **arr, int i, int j) {
    char *tmp = arr[i];
    
    arr[i] = arr[j];
    arr[j] = tmp;
}

static bool cmp(char *s1, char *s2, bool flag_r) {
    int strdif = mx_strcmp(s1, s2);
    bool rslt = flag_r ? strdif < 0 : strdif > 0;
    
    return rslt;
}

static int partition(char **arr, int l, int r, bool flag_r) {
    int p = (r + l) / 2;

    while (l < r) {
        for (;cmp(arr[p], arr[l], flag_r) && l < p; l++);
        for (;cmp(arr[r], arr[p], flag_r) && r > p; r--);
        if (l < r && cmp(arr[l], arr[r], flag_r)) {
            p = l * (p == r) + r * (p == l) + p * (p != l && p != r);
            swapstr(arr, l, r);
        }
        l += 1 * (l != p);
        r -= 1 * (r != p);
    }
    return p;
}

void mx_sort_alphabetically(char **arr, int l, int r, bool flag_r) {
    int p;

    if (arr && l < r) {
        p = partition(arr, l, r, flag_r);
        mx_sort_alphabetically(arr, l, p - 1, flag_r);
        mx_sort_alphabetically(arr, p + 1, r, flag_r);
    }
}
