#include "libmx.h"

char *mx_itoa(int number) {
    char *result = NULL;
    t_calcul itoa = {mx_mod(number), mx_mod(number), 0, 0, 10};

    for (itoa.size = (number <= 0) ? 1 : 0; itoa.number > 0; itoa.size++)
        itoa.number /=itoa.base;

    result = mx_strnew(itoa.size);

    for (int i = itoa.size - 1; result != NULL && i >= 0; i--) {
        if (i == 0 && number < 0) {
            result[i] = '-';
            break;
        }
        itoa.number = itoa.quot;
        itoa.quot = itoa.number / itoa.base;
        itoa.rem = itoa.number % itoa.base;

        result[i] = (itoa.rem + 48);
    }
    return result;
}
