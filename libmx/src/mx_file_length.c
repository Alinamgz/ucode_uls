#include "libmx.h"

int mx_file_length(const char *filename) {
	int fd = open(filename, O_RDONLY);
	int len = 0;
	char buffer = 0;

	if (fd == -1)
		return -1;
	while (read(fd, &buffer, 1) > 0)
		++len;
	close(fd);
	return len;
}
