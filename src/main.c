#include "uls.h"

// TODO: del .travis.yml before pushing to ucode gitlab!

int main(int argc, char **argv) {
    t_parse *parse = (t_parse *)malloc(sizeof(t_parse));
    char current_path[] = ".";
    char *path = current_path;

    if (argc == 1) {
        list_directory(parse, path);
        return 0;
    } else {
        mx_init_parsing(parse);
        mx_parse_input(argc, argv, parse);
        output_ls(parse, path);
    }
    // mx_printstr("\n\n------------------ main --------------------\n");
    // system("leaks -q  uls");
    return 0;
}
