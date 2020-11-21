#include "uls.h"

void mx_parse_input(int argc, char **argv, t_parse *p) {
    int index = 0;

    index = mx_parse_flags(argc, argv, p);

    if(argv[index]) {
        mx_parse_addresses(index, argc, argv, p);
        mx_sort_addresses(p);
    }
}
