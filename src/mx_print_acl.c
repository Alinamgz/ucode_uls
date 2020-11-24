#include "uls.h"

void mx_print_acl(char *fullpath) {
    acl_t my_acl = NULL;
	char  *text_acl = NULL;
	ssize_t len;

    my_acl = acl_get_file(fullpath, ACL_TYPE_EXTENDED);
	if (my_acl == NULL) {
        return;
	}
		text_acl = acl_to_text(my_acl, &len);
        mx_printstr(text_acl);
        acl_free (my_acl);
}
