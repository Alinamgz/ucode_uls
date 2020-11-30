#include "uls.h"

void mx_init_parsing (t_parse *p) {
    p->flags = NULL;
    p->addresses = NULL;
    p->files = NULL;
    p->dirs = NULL;
    p->invalid = NULL;
    p->content_of_directory = NULL;
    p->count_of_objects = 0;
    p->count_of_files = 0;
    p->count_of_dirs = 0;
    p->nopermis = NULL;
}
