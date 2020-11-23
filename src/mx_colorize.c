#include "uls.h"

void mx_colorize(struct stat forstat) {
	switch (forstat.st_mode & S_IFMT) {
		case S_IFBLK:
			mx_printstr(RED);
			break;
		case S_IFDIR:
			mx_printstr(BOLD);
			mx_printstr(CYAN);
			break;
		case S_IFLNK:
			mx_printstr(MAGENTA);
			break; 
		default: 
			if (forstat.st_mode & S_IXUSR) {
				 mx_printstr(RED);
			}
			else {
				mx_printstr(RESET_COLORS);
			}
			break;
	}
}
