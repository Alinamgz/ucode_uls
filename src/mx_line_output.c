#include "uls.h"

static int big_word(t_parse *p) {
    int ln = 0;
    int ln_tmp = 0;

    for (int i = 0; i < p->count_of_objects; i++) {
        ln_tmp = mx_strlen(p->content_of_directory[i]);
        if (ln_tmp > ln)
            ln = ln_tmp;
    }
    return ln;
}

static int ln_terminal(int first_ln) { // try to make loop
    if (first_ln % 8 == 0)
        first_ln += 8;
    else if ((first_ln + 1) % 8 == 0) 
        first_ln++;
    else if ((first_ln + 2) % 8 == 0)
        first_ln += 2;
    else if ((first_ln + 3) % 8 == 0)
        first_ln += 3;  
    else 
        first_ln += 4;

    if (first_ln % 8 != 0) 
        while (first_ln % 8 != 0)
            first_ln++;

    return first_ln;
}

void mx_line_output(t_parse *p, t_flags *f) {
    struct winsize size_wind;
    int first_ln = 0;
    int max_width = 0;

    ioctl(1, TIOCGWINSZ, &size_wind);
    max_width = isatty(1) ? size_wind.ws_col : 79;
    first_ln = big_word(p);

    if (isatty(1)){
        first_ln = f->lg_G ? (first_ln + 1) : ln_terminal(first_ln);
    }
    else {
        first_ln = first_ln + 2;
    }
    
    if (first_ln * p->count_of_objects <= max_width)
        mx_print_in_line(p, first_ln, f);
    else
        mx_print_in_multiline(p, first_ln, max_width, f);

}
