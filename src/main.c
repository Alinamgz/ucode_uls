#include "uls.h"

//TODO: del .travis.yml before pushing to ucode gitlab!

int main(int argc, char **argv) {
    t_parse *parse = (t_parse*)malloc(sizeof(t_parse));
    parse->flags = NULL;
    parse->addresses = NULL;

    argc == 1 ? mx_printstr(HELLO_MSG) : mx_parse_input(argc, argv, parse);

    if (parse->flags) {
        mx_printstr("\n\n=========== flags ==============\n");
            mx_printstr(parse->flags);
    }
    if (parse->addresses) {
        mx_printstr("\n\n=========== files ==============\n");
        for(int i = 0; parse->addresses[i]; i++) {
            mx_printchar('\t');
            mx_printstr(parse->addresses[i]);
        }
        mx_printstr("\n\n");

    }
    system("leaks -q  uls");

    return 0;
}
