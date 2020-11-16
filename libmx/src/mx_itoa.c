#include "libmx.h"

char *mx_itoa(int number) {
    int i = 0; 
    int size = 0;
    int sign;
    char *s = NULL;
    int temp_number = number;

    while ((temp_number /= 10) > 0)
        size++;
    s = mx_strnew(size + 1);
    if ((sign = number) < 0)
        number = -number;
    s[i++] = number % 10 + '0'; 
    while ((number /= 10) > 0)
        s[i++] = number % 10 + '0';
    if (sign < 0)
        s[i++] = '-';
    custom_swap_char(s);
    return s;
}
