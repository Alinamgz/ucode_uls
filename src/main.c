#include "uls.h"

// TODO: del .travis.yml before pushing to ucode gitlab!

int main(int argc, char **argv) {
    t_parse *parse = NULL;
    // t_parse *parse = (t_parse *)malloc(sizeof(t_parse));

    if (argc == 1) {
        list_directory(".");
        return 0;
    } else {
        parse = (t_parse *)malloc(sizeof(t_parse));
        mx_init_parsing(parse);
        mx_parse_input(argc, argv, parse);
        if (parse->flags) {
            mx_printstr("flags: ");
            mx_printstr(parse->flags);
            mx_printchar('\n');
        }

        if (parse->addresses) {
            //  ---- check -----
            for (int i = 0; mx_strlen(parse->addresses[i]); i++) {
                 mx_printchar('\t');
                mx_printstr(parse->addresses[i]);
            }
        }
        // output_ls(parse);
    }
    mx_printstr("\n\n------------------ main --------------------\n");
    system("leaks -q  uls");
    return 0;
}
