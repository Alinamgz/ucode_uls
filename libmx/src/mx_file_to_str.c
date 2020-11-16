#include "libmx.h"

char *mx_file_to_str(const char *file) {
	char *str = NULL;
	int length = mx_file_length(file);
	int fd = open(file, O_RDONLY);
	char buffer;

	if (fd == -1)
		return NULL;
	str = mx_strnew(length);
	if (str == NULL)
		return NULL;
	else {
		for (int i = 0; read(fd, &buffer, 1); i++)
                str[i] = buffer;
            close(fd);
            return str;
	}
	return NULL;
}
