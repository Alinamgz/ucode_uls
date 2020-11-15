#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int rslt = -1;
    int cmp_rslt = 0;

    if (str && sub) {
        rslt = 0;
        for (int i = 0; str[i]; i++) {
            if (str[i] == sub[0]) {
                cmp_rslt = mx_check_substr((str + i), sub);

                if (cmp_rslt == 0) {
                    rslt++;
                }
            }
        }
    }
    return rslt;
}
