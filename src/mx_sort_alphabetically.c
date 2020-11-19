#include "uls.h"

// static inline void swap_str(char **arr, int si_1, int si_2) {
//     char *tmp = arr[si_1];

//     arr[si_1] = arr[si_2];
//     arr[si_2] = tmp;
// }

// void mx_sort_alphabetically(char **arr, int left, int right) {
//     int p = left + (right - left) / 2;
//     int i = left;
//     int j = right;

//     if (arr && left < right) {
		
//         while (mx_strcmp(arr[i], arr[p]) < 0) {
//             i++;
//         }
				
//         while (mx_strcmp(arr[j], arr[p]) > 0) {
//             j--;
//         }

//         if (i < j && mx_strcmp(arr[j], arr[p]) != 0) {
//             swap_str(arr, i, j);
//         }

//         if (++i < right)
//             mx_sort_alphabetically(arr, i, right);

//         if (--j > left)
//             mx_sort_alphabetically(arr, left, j);
//     }
// }

static void swap_str(char **a, char **b) {
    char *temp = *a;

    *a = *b;
    *b = temp;
}

static int partition (char **arr, int l, int r) {  
    int p = (r + l) / 2;

    while (l < r) {
        for(; mx_strcmp(arr[l], arr[p]) < 0 && l < p; l++);
        // for (;mx_strlen(arr[l]) < mx_strlen(arr[p]) && l < p; l++);
        for(; mx_strcmp(arr[r], arr[p]) > 0 && r > p; r--);
        // for (;mx_strlen(arr[r]) > mx_strlen(arr[p]) && r > p; r--);
        if (l < r && mx_strcmp(arr[l], arr[r]) > 0){
        // if (l < r && mx_strlen(arr[l]) > mx_strlen(arr[r])) {
            p = l * (p == r) + r * (p == l) + p * (p != l && p != r);
            swap_str(&arr[l], &arr[r]);
        }
        l += 1 * (l != p);
        r -= 1 * (r != p);
    }
    return p;
}
// int mx_quicksort(char **arr, int left, int right) {
void mx_sort_alphabetically(char **arr, int left, int right) {
    int p;

    if (arr == NULL)
        return;
    if (left < right) {
        p = partition(arr, left, right);
        mx_quicksort(arr, left, p - 1);
        mx_quicksort(arr, p + 1, right);
    }
}
