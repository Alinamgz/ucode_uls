#include "uls.h"

// TODO: del .travis.yml before pushing to ucode gitlab!

int main(int argc, char **argv) {
    t_parse *parse = (t_parse *)malloc(sizeof(t_parse));
    t_flags flags = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int rslt = 0;

    parse->path_pref = ".";
    if (argc == 1 && argv) {
        mx_list_directory(parse, &flags);
        return 0;
    }
    else {
        mx_init_parsing(parse);
        mx_parse_input(argc, argv, parse, &flags);
        if (parse->invalid)
            mx_output_invalid_addr(parse->invalid);
        mx_output_ls(parse, &flags);
    }
    mx_free_malloc(parse, &rslt);

    // mx_printstr("\n -------------- main -----------\n");
    // system("leaks -q uls");

    return rslt;
}
