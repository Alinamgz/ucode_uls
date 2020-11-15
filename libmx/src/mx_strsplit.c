#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    t_strsplit cur = {NULL, (char *)s, 0, 0, 0};

    if (cur.buf_s) {
        cur.w_cnt = mx_count_words(s, c);
        cur.rslt = (char **)malloc(sizeof(char *) * (cur.w_cnt + 1));

        for (cur.i = 0; cur.rslt && cur.i < cur.w_cnt; cur.i++) {
            while (*cur.buf_s == c) {
                cur.buf_s++;
            }
            cur.w_len = 0;
            while (cur.buf_s[cur.w_len] && cur.buf_s[cur.w_len] != c) {
                cur.w_len++;
            }
            cur.rslt[cur.i] = mx_strndup(cur.buf_s, cur.w_len);
            cur.buf_s += cur.w_len;
        }
        cur.rslt[cur.i] = NULL;
    }
    return cur.rslt;
}
