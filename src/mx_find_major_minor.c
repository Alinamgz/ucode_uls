#include "uls.h"

void mx_find_major_minor(int number, t_forlong *forlong) {
    int binary[32];
    int i = 0;
    forlong->major = 0;
    forlong->minor = 0;

    for (; number > 0; i++) {    
        binary[i] = number % 2;    
        number = number / 2;
    }
    while (i < 32) {
        binary[i] = 0;
        i++;
    }
    i -= 8;
    for (int j = 0; i != 32 ; j++) {
        forlong->major += binary[i] * mx_pow(2, j);
        ++i;
    }
    i = 0;
    for (int j = 0; i != 14; j++) {
        forlong->minor += binary[i] * mx_pow(2, j);
        ++i;
    }
}
