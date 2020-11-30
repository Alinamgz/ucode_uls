#include "uls.h"

static bool is_upper(int c) {
	if (c >= 65 && c <= 90)
		return true;
	else
		return false;
}

void mx_print_acl(char *fullpath) {
    acl_t my_acl = NULL;
	char  *text_acl = NULL;
	ssize_t len;
    int i = 0;
    int j = 0;

    my_acl = acl_get_file(fullpath, ACL_TYPE_EXTENDED);
	if (my_acl == NULL) {
        return;
	}
    mx_printchar('\n');
		text_acl = acl_to_text(my_acl, &len);
        for ( ; text_acl[i] != '\0'; i++) {
            if (i == 0) {
                mx_printchar(' ');
                mx_printint(0);
                mx_printstr(": ");
            }
            if (text_acl[i] == '!' && text_acl[i + 1] == '#')
                i += 8;
            if (mx_isdigit(text_acl[i]) || is_upper(text_acl[i])
                || text_acl[i] == '-' || text_acl[i] == '\n')
                continue;
            if (text_acl[i] == ':') {
                if (j == 0) {
                    mx_printchar(':');
                    j += 1;
                }
                else if (j > 0 && i > 60)
                    mx_printchar(' ');
                continue;
            }

            mx_printchar(text_acl[i]);
        }
        acl_free (my_acl);
}
