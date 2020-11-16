#include "uls.h"

// TODO: del .travis.yml before pushing to ucode gitlab!

int main(int argc, char **argv) {
    t_parse *parse = NULL;

    if (argc == 1) {
        list_directory(".");
        return 0;
    } else {
        parse = (t_parse *)malloc(sizeof(t_parse));
        mx_init_parsing(parse);
        mx_parse_input(argc, argv, parse);
        if (parse->flags) {
            mx_validate_flags(parse);
        }

        if (parse->addresses) {
            mx_validate_addr(parse);
        }

        output_ls(parse);
    }
    mx_printstr("\n\n------------------ main --------------------\n");
    system("leaks -q  uls");
    return 0;
}
