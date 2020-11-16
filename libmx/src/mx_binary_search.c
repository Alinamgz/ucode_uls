#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int left = 0;
    int right = size - 1;
    int mid;
    int comp;

    while (left <= right) {
        *count += 1;
        mid = left + ((right - left) / 2);
        comp = mx_strcmp(arr[mid], s);

        if ( comp == 0)
            return mid;
        else if (comp < 0)
            left = mid + 1;
        else if (comp > 0)
            right = mid - 1;
    }
    *count = 0;
    return -1;
}
