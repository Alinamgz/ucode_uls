#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
	char *result = NULL;
	size_t dst_len = (mx_strlen(s1) < (int)n) ? mx_strlen(s1) : n;

	result = mx_strnew(dst_len);

	mx_strncpy(result, s1, dst_len);

	return result;
}


