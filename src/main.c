#include "uls.h"

// TODO: del .travis.yml before pushing to ucode gitlab!

int main(int argc, char **argv) {
    t_parse *parse = NULL;
    t_direct *direct = (t_direct *)malloc(sizeof(t_direct));

    directory_info(direct);
    if (argc == 1) {
        list_directory(direct);
        return 0;
    } else {
        parse = (t_parse *)malloc(sizeof(t_parse));
        mx_init_parsing(parse);
        mx_parse_input(argc, argv, parse);
 
        output_ls(parse, direct);
    }
    // mx_printstr("\n\n------------------ main --------------------\n");
    // system("leaks -q  uls");
    return 0;
}
