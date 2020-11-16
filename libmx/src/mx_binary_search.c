#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    t_bin_search search = {0, (size - 1), 0, 0};

    while (search.left <= search.right) {
        *count += 1;
        search.mid = search.left + ((search.right - search.left) / 2);
        search.comp = mx_strcmp(arr[search.mid], s);

        if ( search.comp == 0)
            return search.mid;
        else if (search.comp < 0)
            search.left = search.mid + 1;
        else if (search.comp > 0)
            search.right = search.mid - 1;
    }

    *count = 0;
    return -1;
}
