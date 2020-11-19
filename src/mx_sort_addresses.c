#include "uls.h"

static inline bool is_file(const char *addr) {
    int fd = open(addr, O_RDONLY);
    bool rslt = fd < 0 ? 0 : 1;
    if (fd >= 0) close(fd);

    return rslt;
}

static inline bool is_dir(const char *addr) {
    DIR *dp = opendir(addr);
    bool rslt = dp ? 1 : 0;
    if (dp) closedir(dp);

    return rslt;
}

void mx_sort_addresses(t_parse *p, int size) {
    int inv = 0;
    int d = 0;
    int f = 0;
    int i = 0;

    p->invalid = (char**)malloc(sizeof(char*) * size);
    p->dirs = (char**)malloc(sizeof(char*) * size);
    p->files = (char**)malloc(sizeof(char*) * size);

    for (i = 0; i < size; i++) {
        p->invalid[i] = NULL;
        p->dirs[i] = NULL;
        p->files[i] = NULL;
    }

if (p) mx_printstr("todo sort\n");
    for (i = 0; p->addresses[i]; i++) {
        if (is_dir(p->addresses[i])) {
            p->dirs[d++] = mx_strdup(p->addresses[i]);
        }
        else if (is_file(p->addresses[i])) {
            p->files[f++] = mx_strdup(p->addresses[i]);
        }
        else {
            p->invalid[inv++] = mx_strdup(p->addresses[i]);
        }
    }
    mx_del_strarr(&p->addresses);
} 
