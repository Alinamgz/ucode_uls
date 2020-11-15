#include "libmx.h"

// cmp = (a > b) ? true : false

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    t_list *temp;
    t_list *buff = lst;
    bool cmp_rslt = false;
    int lst_len = mx_list_size(buff);

    for (int i = lst_len - 1; i > 0; i--) {
        buff = lst;
        for (int j = 0; j < i; j++) {
            cmp_rslt = cmp(buff->data, buff->next->data);
            if (cmp_rslt == true) {
                temp = buff->data;
                buff->data = buff->next->data;
                buff->next->data = temp;
            }
            buff = buff->next;
        }
    }
    return lst;
}
