#include "uls.h"

void print_time(struct stat forstat) {
    char *current_time_zone = mx_strnew(12);
    time_t time_in_seconds;
    time_in_seconds = time(NULL);

    current_time_zone[0] = ctime(&forstat.st_mtime)[4];
    current_time_zone[1] = ctime(&forstat.st_mtime)[5];
    current_time_zone[2] = ctime(&forstat.st_mtime)[6];
    current_time_zone[3] = ctime(&forstat.st_mtime)[7];
    current_time_zone[4] = ctime(&forstat.st_mtime)[8];
    current_time_zone[5] = ctime(&forstat.st_mtime)[9];
    current_time_zone[6] = ctime(&forstat.st_mtime)[10];
    if (forstat.st_mtime < (time_in_seconds - 15552000)) {
        current_time_zone[7] = ctime(&forstat.st_mtime)[19];
        current_time_zone[8] = ctime(&forstat.st_mtime)[20];
        current_time_zone[9] = ctime(&forstat.st_mtime)[21];
        current_time_zone[10] = ctime(&forstat.st_mtime)[22];
        current_time_zone[11] = ctime(&forstat.st_mtime)[23];
    }
    if (forstat.st_mtime > (time_in_seconds - 15552000)) {
        current_time_zone[7] = ctime(&forstat.st_mtime)[11];
        current_time_zone[8] = ctime(&forstat.st_mtime)[12];
        current_time_zone[9] = ctime(&forstat.st_mtime)[13];
        current_time_zone[10] = ctime(&forstat.st_mtime)[14];
        current_time_zone[11] = ctime(&forstat.st_mtime)[15];
    }

    mx_printstr(current_time_zone);
    free(current_time_zone);
}
