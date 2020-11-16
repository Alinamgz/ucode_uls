#include "libmx.h"

void mx_pop_back(t_list **list) {
    t_list *temp = NULL;

    if (list == NULL || *list == NULL) {
        return;
    }

    temp = *list;
    if (temp->next == NULL) {
        free(*list);
        *list = NULL;
        return;
    }
    else {
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}
