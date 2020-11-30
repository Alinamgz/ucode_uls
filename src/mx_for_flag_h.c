#include "uls.h"

static void convert(t_forlong *forlong, int number, char *type, int n) {
    char *temp;

    float fres = (float)number / (float)n;
    float fpart = fres - (number / n);
    if (fpart >= 0.5)
            fres += 1;
    forlong->suffix_size = mx_strnew(mx_intlen((int)fres) + 1);
    temp = mx_itoa((int)fres);
    forlong->suffix_size = mx_strcpy(forlong->suffix_size, temp);
    forlong->suffix_size = mx_strcat(forlong->suffix_size, type);
    mx_strdel(&temp);
}

static void convert_float(t_forlong *forlong, int number, char *type, int n) {
    float f_size;

    f_size = (float)number / (float)n;
    number /= n;
    forlong->suffix_size = mx_strnew(mx_intlen(number) + 3);
    mx_float_to_char(f_size, forlong->suffix_size, 1);
    forlong->suffix_size = mx_strcat(forlong->suffix_size, type);
}

 void mx_for_flag_h(t_forlong *forlong, int number) {
     forlong->suffix_size = NULL;

    if (number < 0 || number > 2147483647)
        return;
    if (number == 0) {
        forlong->suffix_size = mx_strnew(2);
        forlong->suffix_size = mx_strcpy(forlong->suffix_size, "0B");
    }
    else if (number > 0 && number <= 1024)
        convert(forlong, number, "B", 1);
    else if (number > 1024 && number <= 1048576) {
        if (number < 10240)
            convert_float(forlong, number, "K", 1024);
        else
            convert(forlong, number, "K", 1024);
    }
    else if (number > 1048576 && number <= 1073741824) {
        convert(forlong, number, "M", 1048576);
    }
    else {
        convert(forlong, number, "G", 1073741824);
    }
}
