#include "uls.h"

void mx_free_malloc(t_parse *parse, int *rslt) {
   
    if (parse->invalid){
        mx_del_strarr(&parse->invalid);
        *rslt = 1;
        }
    if (parse->addresses)
        mx_del_strarr(&parse->addresses);
    if (parse->files)
        mx_del_strarr(&parse->files);
    if (parse->dirs)
        mx_del_strarr(&parse->dirs);
    if (parse->invalid)
        mx_del_strarr(&parse->invalid);
    if (parse->flags)
        mx_strdel(&parse->flags);

    free(parse);
}
