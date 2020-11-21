#include "uls.h"

void mx_get_acl_xattr(char *path) {
    acl_t acl = NULL;
    ssize_t xattr = 0;

    acl = acl_get_file(path, ACL_TYPE_EXTENDED); // try to change with mask
    xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
    if (xattr > 0)
        mx_printchar('@');
    else if (acl != NULL)
        mx_printchar('+');
    else
        mx_printchar(' ');
    acl_free(acl);
}
