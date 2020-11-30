#include "uls.h"

void mx_print_xattr(char *fullpath) {
    ssize_t buflen;
    ssize_t keylen;
    ssize_t vallen;
    char *buf = NULL;
    char *key = NULL;
    char *val = NULL;
    
    buflen = listxattr(fullpath, NULL, 0, XATTR_NOFOLLOW);
    if (buflen == -1)
        return;
    if (buflen == 0)
        return;
    buf = malloc(buflen);
    if (buf == NULL)
        return;
    buflen = listxattr(fullpath, buf, buflen, XATTR_NOFOLLOW);
    if (buflen == -1)
        return;
    key = buf;
    while (buflen > 0) {
        mx_printstr("\n");
        mx_printstr("\t");
        mx_printstr(key);

        vallen = getxattr(fullpath, key, NULL, 0, 0, XATTR_NOFOLLOW);
        if (vallen == -1)
            return;
        if (vallen == 0) {
                mx_printstr("\t");
                mx_print_lnumber(vallen, 4);
        }
        if (vallen > 0) {
            val = malloc(vallen + 1);
            if (val == NULL) {
               return;
            }
            vallen = getxattr(fullpath, key, val, vallen, 0, XATTR_NOFOLLOW);
            if (vallen == -1)
                return;
            else {
                val[vallen] = 0;
                mx_printstr("\t");
                mx_print_lnumber(vallen, 4);
            }
            free(val);
        }
            
        keylen = strlen(key) + 1;
        buflen -= keylen;
        key += keylen;
    mx_printchar(' ');
    }
    free(buf);
}
