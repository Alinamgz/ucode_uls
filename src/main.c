#include "uls.h"

// TODO: del .travis.yml before pushing to ucode gitlab!

int main(int argc, char **argv) {
    t_parse *parse = (t_parse *)malloc(sizeof(t_parse));
    t_flags flags = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char current_path[] = ".";
    char *path = current_path;
    int rslt = 0;

    if (argc == 1) {
        mx_list_directory(parse, path, &flags);
        free(parse);
        return 0;
    }
    else {
        mx_init_parsing(parse);
        mx_parse_input(argc, argv, parse, &flags);
        if (parse->invalid || parse->nopermis)
            mx_output_invalid_addr(parse);
        mx_output_ls(parse, path, &flags);
    }
    //system("leaks -q uls");
    mx_free_malloc(parse, &rslt);
    return rslt;
}
