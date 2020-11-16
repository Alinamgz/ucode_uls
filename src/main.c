#include "uls.h"

//TODO: del .travis.yml before pushing to ucode gitlab!

static inline bool is_flag(const char *str) {
    bool rslt = str[0] == '-' && (mx_strlen(str) > 1) ? 1 : 0;
    return rslt;
}

int main(int argc, char **argv) {
    //char *flg = NULL;
    char *flags_draft = NULL;
    char **files = NULL;
    int i = 0;
    int j = 0;
    int k = 0;

    if (argc == 1) {
        mx_printstr(HELLO_MSG);
    }
    else {
        if (is_flag(argv[1])) {
            for(j = 1; j < argc && is_flag(argv[j]); j++) {
                //flg = argv[j];
                flags_draft = mx_strjoin(flags_draft, argv[j] + 1);
            }
        }

        files = (char**)malloc(sizeof(char*) * argc);
        for (i = 0; i <= argc; i++) {
            files[i] = NULL;
        }
        for(; j < argc; j++) {
            files[k++] = mx_strdup(argv[j]);
        }
    }

    if (flags_draft) {
        mx_printstr("\n\n=========== flags ==============\n");
            mx_printstr(flags_draft);
        }
        if (files) {
            mx_printstr("\n\n=========== files ==============\n");
            for(i = 0; files[i]; i++) {
                mx_printchar('\t');
                mx_printstr(files[i]);
            }

        }
mx_printstr("\ncheck\n");

    return 0;
}
