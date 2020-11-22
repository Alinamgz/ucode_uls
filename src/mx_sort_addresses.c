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

static inline void pre_sorting (t_parse *p, t_sort *s) {
    for (s->j = 0; p->addresses[s->j]; s->j++) {
        if (is_dir(p->addresses[s->j])) {
            s->addr_sort[s->j] = 'd';
            s->d++;
        }
        else if (is_file(p->addresses[s->j])) {
            s->addr_sort[s->j] = 'f';
            s->f++;
        }
        else {
            s->addr_sort[s->j] = 'i';
            s->i++;
        }
    }
}

static inline void init_addr_arrays(t_parse *p, t_sort *s) {
    if (s->d)
        p->dirs = (char**)malloc(sizeof(char*) * (s->d + 1));
    if (s->f)
        p->files = (char**)malloc(sizeof(char*) * (s->f + 1));
    if (s->i)
        p->invalid = (char**)malloc(sizeof(char*) * (s->i + 1));

    s->d = 0;
    s->f = 0;
    s->i = 0;
}

static inline void fill_addr_arrays(t_parse *p, t_sort *s) {
    for(s->j = 0; p->addresses[s->j]; s->j++) {
        if(s->addr_sort[s->j] == 'd') {
            p->dirs[s->d++] = mx_strdup(p->addresses[s->j]);
            p->dirs[s->d] = NULL;
            p->count_of_dirs++;
        }
        else if (s->addr_sort[s->j] == 'f') {
            p->files[s->f++] = mx_strdup(p->addresses[s->j]);
            p->files[s->f] = NULL;
            p->count_of_files++;
        }
        else if (s->addr_sort[s->j] == 'i'){
            p->invalid[s->i++] = mx_strdup(p->addresses[s->j]);
            p->invalid[s->i] = NULL;
        }
    }
}

void mx_sort_addresses(t_parse *p, t_flags *f, int size) {
    t_sort s = {0, 0, 0, 0, mx_strnew(size)};

    pre_sorting(p, &s);
    init_addr_arrays(p, &s);
    fill_addr_arrays(p, &s);

    if (p->dirs)
         mx_sort_alphabetically(p->dirs, 0, (s.d - 1), f->lg_r);
    if (p->files)
        mx_sort_alphabetically(p->files, 0, (s.f - 1), f->lg_r);
    if (p->invalid)
        mx_sort_alphabetically(p->invalid, 0, (s.i - 1), 0);

    mx_strdel(&s.addr_sort);
} 
