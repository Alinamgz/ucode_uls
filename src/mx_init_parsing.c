#include "uls.h"

void mx_init_parsing (t_parse *p) {
    p->flags = NULL;
    // p->flags_state = NULL;
    p->target = NULL;
    p->addresses = NULL;
    p->files = NULL;
    p->dirs = NULL;
    p->invalid = NULL;
    p->content_of_directory = NULL;
}
