#include "libmx.h"

int mx_get_char_index(const char *str, char c) {
	int rslt = -2;

	if (str) {
		for (rslt = 0; str[rslt]; rslt++) {
			if(str[rslt] == c) {
				return rslt;
			}
		}
		rslt = -1;
	}

	return rslt;
}
