#include "libmx.h"

void mx_only_printable(void) {
    for (char target = 126; target < 127 && target >= 32; target--) {
        mx_printchar(target);
    };
        mx_printchar('\n');
}
