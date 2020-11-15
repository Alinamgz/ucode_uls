#include "libmx.h"

int mx_list_size(t_list *list) {
    int result= 0;

    while(list != NULL) {
        result++;
        list = list->next;
    }

    return result;
}
