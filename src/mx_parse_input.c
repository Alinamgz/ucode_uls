#include "uls.h"

static inline bool is_flag(const char *str) {
    bool rslt = str[0] == '-' && (mx_strlen(str) > 1) ? 1 : 0;
    return rslt;
}

static inline void pick_unique_flags(const char *str, t_parse *p) {
    char buf[2] = {'\0', '\0'};
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
}

void mx_parse_input(int argc, char **argv, t_parse *p) {
    int i = 0;
    int j = 0;
    int k = 0;

    if (is_flag(argv[1])) {
        for(j = 1; j < argc && is_flag(argv[j]); j++) {
            pick_unique_flags(argv[j], p);
        }
    }
    p->addresses = (char**)malloc(sizeof(char*) * (argc - j + 1));
    for (i = 0; i <= (argc - j + 1); i++) {
        p->addresses[i] = NULL;
    }
    for(; j < argc; j++) {
        p->addresses[k++] = mx_strdup(argv[j]);
    }
    p->addresses[k++] = mx_strnew(1); // need to additional free 
}
