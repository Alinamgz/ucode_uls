#include "uls.h"

char *mx_custom_nbr_to_hex(unsigned long nbr, t_forlong *f) {
    char *result = NULL;
    int j = 4;
    t_calcul to_hex = {nbr, nbr, 0, 0, 16};

    for (; to_hex.number > 0; to_hex.size++)
        to_hex.number /= to_hex.base;
    result = mx_strnew(10);
    for (; result && to_hex.size > 0; to_hex.size--) {
        to_hex.number = to_hex.quot;
        to_hex.quot = to_hex.number / to_hex.base;
        to_hex.rem = to_hex.number % to_hex.base;
        if (to_hex.rem >= 10)
            result[to_hex.size - 1] = (to_hex.rem + 87);
        else
            result[to_hex.size - 1] = (to_hex.rem + 48);
    }
    f->forhex = mx_strnew(10);
    for (int i = 0; i < 10; i++) {
        if (i == 1)
            f->forhex[i] = 'x';
        else if (i > 5) {
            f->forhex[i] = result[j];
            j++;
        }
        else
            f->forhex[i] = '0';
    }
    free(result);
    return f->forhex;
}
