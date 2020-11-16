#include "libmx.h"

int mx_bubble_sort(char **arr, int size) {
    int i, j;
    int count = 0;
    char *temp;
    
        for (i = 0; i < size; ++i) 
        {
            for (j = i + 1; j < size; ++j)
            {
                if (mx_strcmp(arr[i], arr[j]) > 0) 
                {
                    ++count;
                    temp =  arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        return count;
}
