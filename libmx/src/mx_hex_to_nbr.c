#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long result = 0;
    int count;
    unsigned long mult = 1;

    for(count = 0; hex[count] != '\0';count++);
    for(int i = count - 1; i >= 0; i--){
        if (mx_isdigit(hex[i]))
            result += (hex[i] - 48) * mult;
        else if (mx_isalpha(hex[i])){
            if (mx_islower(hex[i]) && hex[i] <= 'f')
                result += (hex[i] - 87) * mult;
            else if (mx_isupper(hex[i]) && hex[i] <= 'F')
                result += (hex[i] - 55) * mult;
            else 
                return 0;
        } else 
            return 0;
        mult *= 16;
    }
    return result;
}
