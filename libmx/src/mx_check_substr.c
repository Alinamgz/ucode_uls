#include <libmx.h>

int mx_check_substr(const char *src, const char *sub) {
    int rslt = 0;

    for (int i = 0; sub[i]; i++) {
        if (src[i] != sub[i]) {
            return (src[i] - sub[i]);
        }
    }

    return rslt;
}
