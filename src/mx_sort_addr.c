#include "uls.h"

void mx_sort_addr(t_parse *p) {
    if (p)
    mx_quicksort(p->addresses, 0, p->right);
        mx_printstr("\n --- \\m/ ama gonna sort yo addrss \\m/ --- \n");
}
