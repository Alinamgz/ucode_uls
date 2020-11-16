#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int num = 0;
    const char *buf = str;

    if (str == NULL || sub == NULL)
        return -1;
    if (mx_strlen(str) == 0 || mx_strlen(sub) == 0)
        return 0;
    while ((buf = mx_strstr(buf, sub)) != 0) {
        num++;
        buf++;
    }
    return num;
}
