#include "uls.h"

// TODO: del .travis.yml before pushing to ucode gitlab!

int main(int argc, char **argv) {
    t_parse *parse = (t_parse *)malloc(sizeof(t_parse));
    t_flags flags = {0, 0, 0, 0};
    char current_path[] = ".";
    char *path = current_path;

    if (argc == 1) {
        list_directory(parse, path, &flags);
        return 0;
    } else {
        mx_init_parsing(parse);
        mx_parse_input(argc, argv, parse, &flags);
        if (parse->invalid)
            mx_output_invalid_addr(parse->invalid);
        if (!parse->addresses) {
            list_directory(parse, path, &flags);
        }
        output_ls(parse, path, &flags);
    }
    // mx_printstr("\n\n------------------ main --------------------\n");
    // system("leaks -q  uls");
    if (parse->invalid)
        return 1;
    return 0;
}
