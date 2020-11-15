#include "libmx.h"

char *mx_file_to_str(const char *file) {
    t_file_to_str fts;
    fts.dst = NULL;
    fts.result = NULL;

    fts.src_fd = open(file, O_RDONLY);
    if (fts.src_fd < 0)
        return NULL;

    while ((fts.src_rslt = read(fts.src_fd, fts.buff, BUFFER_SIZE)) > 0) {
        fts.buff[fts.src_rslt] = 0;
        
        fts.dst = mx_strjoin(fts.result, fts.buff);
        mx_strdel(&fts.result);

        fts.result= mx_strdup(fts.dst);
        mx_strdel(&fts.dst);
    }    
    fts.result = fts.src_rslt < 0  ? NULL : fts.result;

    return fts.result;
}
