#include "uls.h"

static inline void swap_strings(char **arr, int i, int j) {
    char *tmp = arr[i];

    arr[i] = arr[j];
    arr[j] = tmp;
}

static inline void sort_ascending(char **arr, t_sort *s, int left, int right){
    while(mx_strcmp(arr[s->i], arr[s->f]) < 0 && s->i <= right)
        s->i++;
    while(mx_strcmp(arr[s->j], arr[s->f]) > 0 && s->j >= left)
        s->j--;

    if(s->i < s->j) {
        swap_strings(arr, s->i, s->j);
    }
}

static inline void sort_descending(char **arr, t_sort *s, int left, int right){
    while(mx_strcmp(arr[s->i], arr[s->f]) > 0 && s->i <= right)
        s->i++;
    while(mx_strcmp(arr[s->j], arr[s->f]) < 0 && s->j >= left)
        s->j--;

    if(s->i < s->j) {
        swap_strings(arr, s->i, s->j);
    }
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

        mx_sort_alphabetically(arr, left, s.j - 1, flag_r);
        mx_sort_alphabetically(arr, s.j + 1, right, flag_r);
    }
}
