#include "libmx.h"

int mx_count_words(const char *str, char delimiter) {
    int result = str ? 0 : -1;

    for (int i = 0; str && str[i] !='\0'; i++) {
        if(str[i] != delimiter) {
            if (str[i+1] == delimiter || str[i+1] == '\0') {
                result +=1;
            }
        } 
    }

    return result;
}
