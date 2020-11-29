#include "uls.h"

void mx_free_malloc(t_parse *parse, int *rslt) {
    if (parse->invalid){
        mx_del_strarr(&parse->invalid);
        *rslt = 1;
    }
    if (parse->addresses) {
        for (int i = 0; parse->addresses[i]; i++)
            free(parse->addresses[i]);
        if (parse->addresses)
            free(parse->addresses);
    }
    if (parse->files)
        mx_del_strarr(&parse->files);
    if (parse->dirs)
        mx_del_strarr(&parse->dirs);
    if (parse->invalid)
        mx_del_strarr(&parse->invalid);
    if (parse->flags)
        mx_strdel(&parse->flags);
    if (parse->nopermis) {
        for (int i = 0; parse->nopermis[i]; i++)
            free(parse->nopermis[i]);
        if (parse->nopermis)
            free(parse->nopermis);
    }
    if (parse->flags)
        mx_strdel(&parse->flags);
    if (parse->count_of_objects)
        free(parse->flags);

    free(parse);
}
