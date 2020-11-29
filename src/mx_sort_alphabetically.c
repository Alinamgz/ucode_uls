#include "uls.h"

/*
static inline void swap_strings(char **arr, int i, int j) {
    char *tmp = arr[i];

    arr[i] = arr[j];
    arr[j] = tmp;
}

static inline void sort_ascending(char **arr, t_sort *s, int left, int right){
    int old_i = s->i;
    int old_j = s->j;

    while(mx_strcmp(arr[s->i], arr[s->f]) < 0 && s->i <= right)
        s->i++;
    while(mx_strcmp(arr[s->j], arr[s->f]) > 0 && s->j >= left)
        s->j--;

    if(s->i < s->j) {
        swap_strings(arr, s->i, s->j);
    }
    s->i += s->i == old_i ? 1 : 0;
    s->j -= s->j == old_j ? 1 : 0;
}

static inline void sort_descending(char **arr, t_sort *s, int left, int right){
    int old_i = s->i;
    int old_j = s->j;
    
    while(mx_strcmp(arr[s->i], arr[s->f]) > 0 && s->i <= right)
        s->i++;
    while(mx_strcmp(arr[s->j], arr[s->f]) < 0 && s->j >= left)
        s->j--;

    if(s->i < s->j) {
        swap_strings(arr, s->i, s->j);
    }
    s->i += s->i == old_i ? 1 : 0;
    s->j -= s->j == old_j ? 1 : 0;
}

void mx_sort_alphabetically(char **arr, int left, int right, bool flag_r) {
    t_sort s = {0, left, left, right, NULL};

    if(left < right) {
        while (s.i < s.j) {
            if (flag_r){
                sort_descending(arr, &s, left, right);
            }
            else {
                sort_ascending(arr, &s, left, right);
            }
        }
        swap_strings(arr, s.j, s.f);
        mx_sort_alphabetically(arr, left, s.j, flag_r);
        mx_sort_alphabetically(arr, s.j + 1, right, flag_r);
    }
}
*/

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
        for (;cmp(arr[p], arr[l]) && l < p; l++);
        for (;cmp(arr[r], arr[p]) && r > p; r--);
        if (l < r && cmp(arr[l], arr[r])) {
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
