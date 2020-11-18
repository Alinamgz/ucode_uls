#include "uls.h"

static int big_word(t_direct *direct) {
    int ln = 0;
    int ln_tmp = 0;

    for (int i = 0; i < direct->count_of_objects; i++) {
        ln_tmp = mx_strlen(direct->content_of_directory[i]);
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
        first_ln = first_ln + 2;
    else if ((first_ln + 3) % 8 == 0)
        first_ln = first_ln + 3;
    else 
        first_ln = 4;

    if (first_ln % 8 != 0) 
        while (first_ln % 8 != 0)
            first_ln++;

    return first_ln;
}

void line_output(t_direct *direct) {
    struct winsize size_wind;
    int first_ln = 0;

    ioctl(1, TIOCGWINSZ, &size_wind);
    first_ln = big_word(direct);
    first_ln = ln_terminal(first_ln);

    //mx_printint(size_wind.ws_col);
    //mx_printchar('\n');

    if (first_ln * direct->count_of_objects <= size_wind.ws_col)
        print_in_line(direct, first_ln);
    else
        print_in_multiline(direct, first_ln, size_wind);
    exit(0);
}
