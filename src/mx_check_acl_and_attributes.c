#include "uls.h"

void mx_check_acl_and_attributes(char *fullpath) {
    acl_t alist = NULL;
    ssize_t attr = 0;

    alist = acl_get_file(fullpath, ACL_TYPE_EXTENDED);
    attr = listxattr(fullpath, NULL, 0, XATTR_NOFOLLOW);
    if (attr > 0)
        mx_printchar('@');
    else if (alist != NULL)
        mx_printchar('+');
    else
        mx_printchar(' ');
    acl_free(alist);
}
