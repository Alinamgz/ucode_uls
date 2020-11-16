#include "libmx.h"

bool mx_isspace(int c) {
    int i = 0;
    char spaces[] = {'\t', '\n', '\v', '\f', '\r', ' '};
    while (i <= 5) {
    if (spaces[i] == c)
        return 1;
    else if (spaces[i] != c && i <= 5)
        i++;
    }
    return 0;    
}
