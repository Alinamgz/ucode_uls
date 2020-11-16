#include "libmx.h"

int mx_sqrt(int x) {
    int numb = 0;
    
    for (int i = 1; i <= x / 2; i++){
        numb = i;
        if (x == numb * numb)
            return numb;
    }
    return 0;
}
