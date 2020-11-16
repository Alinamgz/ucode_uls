#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    int count = 0;
    char *result = NULL;
    unsigned long temp;

    if ((nbr < 0) || (nbr > LONG_MAX))
        return NULL;
    for(temp = nbr; temp > 0; temp = temp / 16)
        count++;
    result = mx_strnew(count);
    for(temp = nbr; temp > 0; temp = temp / 16){
        count--;
        if (temp % 16 < 10)
            result[count] = temp % 16 + 48;
        else 
            result[count] = temp % 16 + 87;
    }   
    return result;
}
