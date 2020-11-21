#include "uls.h"

void mx_parse_input(int argc, char **argv, t_parse *p, t_flags *f) {
    int index = 0;

    index = mx_parse_flags(argc, argv, p);
    mx_switch_flags(p->flags, f);

    if(argv[index]) {
        mx_parse_addresses(index, argc, argv, p, f);
    }
}
