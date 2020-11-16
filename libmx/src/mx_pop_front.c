#include "libmx.h"

void mx_pop_front(t_list **head) {
    t_list *tmp = NULL;

    if (*head == NULL)
        return;
		
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    }
    else {
        tmp = (*head)->next;
        free(*head);
        *head = tmp;
    }
}
