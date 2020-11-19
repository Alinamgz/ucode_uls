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

void mx_sort_addresses(t_parse *p) {
    int d = 0;
    int f = 0;
    int i = 0;
    int j = 0;

    for (j = 0; p->addresses[j]; j++) {
        if (is_dir(p->addresses[j])) {
            p->dirs = (char**)mx_realloc(p->dirs, sizeof(char*) * 2 + d);
            p->dirs[d++] = mx_strdup(p->addresses[j]);
            p->dirs[d] = NULL;
        }
        else if (is_file(p->addresses[j])) {
            p->files = (char**)mx_realloc(p->files, sizeof(char*) * 2 + f);
            p->files[f++] = mx_strdup(p->addresses[j]);
            p->files[f] = NULL;
        }
        else {
            p->invalid = (char**)mx_realloc(p->invalid, sizeof(char*) * 2 + i);
            p->invalid[i++] = mx_strdup(p->addresses[j]);
            p->invalid[i] = NULL;
        }
    }
    mx_del_strarr(&p->addresses);
} 
