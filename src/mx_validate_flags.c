#include "uls.h"

void mx_validate_flags(t_parse *p) {
    char buf[2] = {'\0', '\0'};
    int is_valid = 0;
    int is_dependent = 0;

        for(int i = 0; p->flags[i]; i++) {

        if (VALID_FLAGS)  {
            is_valid = mx_get_char_index(VALID_FLAGS, p->flags[i]);
            is_dependent = mx_get_char_index(DEPENDENT_FLAGS, p->flags[i]);

            if (is_valid < 0 && is_dependent < 0) {
                buf[0] = p->flags[i];
                mx_printerr(ILLEGAL_OPTION);
                mx_printerr(buf);
                mx_printerr(USAGE_START);
                mx_printerr(VALID_FLAGS);
                mx_printerr(USAGE_END);

                exit(1);
            }
        }
    }
}
