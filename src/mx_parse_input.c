#include "uls.h"

// TODO: en dit kak ook
static inline bool is_flag(const char *str) {
    bool rslt = str[0] == '-' && (mx_strlen(str) > 1) ? 1 : 0;
    return rslt;
}

static inline void pick_unique_flags(const char *str, t_parse *p) {
    char *buf = mx_strnew(1);
    char *flags_buf = NULL;

    for (int i = 1; str[i]; i++) {
        if(mx_get_char_index(p->flags, str[i]) < 0) {
            buf[0] = str[i];
            
            flags_buf = mx_strjoin(p->flags,buf);
            mx_strdel(&p->flags);

            p->flags = mx_strdup(flags_buf);
            mx_strdel(&flags_buf);
        }
    }
            mx_strdel(&buf);
}

void mx_parse_input(int argc, char **argv, t_parse *p) {

//  TODO: fix dit kak

    int i = 0;
    int j = 1;
    int k = 0;

    if (is_flag(argv[1])) {
        for(j = 1; j < argc && is_flag(argv[j]); j++) {
            // TODO pick flags assotiated with -l
            pick_unique_flags(argv[j], p);
        }
    }

    p->addresses = (char**)malloc(sizeof(char*) * (argc - j + 2));
    for (i = 0; i <= (argc - j + 2); i++) {
        p->addresses[i] = NULL;
    }
    for(; j < argc; j++) {
        p->addresses[k++] = mx_strdup(argv[j]);
    }
        p->addresses[k++] = mx_strnew(1); // need to additional free 
    p->right = j + 2;
}
