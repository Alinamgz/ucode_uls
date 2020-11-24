#include "uls.h"

void mx_print_time(struct stat forstat, t_flags *f) {
    char *current_time_zone = NULL;
    time_t time_in_seconds;
    time_in_seconds = time(NULL);

    if (f->lg_T) {
        current_time_zone = mx_strnew(20);
        current_time_zone[0] = ctime(&forstat.st_mtime)[4];
        current_time_zone[1] = ctime(&forstat.st_mtime)[5];
        current_time_zone[2] = ctime(&forstat.st_mtime)[6];
        current_time_zone[3] = ctime(&forstat.st_mtime)[7];
        current_time_zone[4] = ctime(&forstat.st_mtime)[8];
        current_time_zone[5] = ctime(&forstat.st_mtime)[9];
        current_time_zone[6] = ctime(&forstat.st_mtime)[10];
        current_time_zone[7] = ctime(&forstat.st_mtime)[11];
        current_time_zone[8] = ctime(&forstat.st_mtime)[12];
        current_time_zone[9] = ctime(&forstat.st_mtime)[13];
        current_time_zone[10] = ctime(&forstat.st_mtime)[14];
        current_time_zone[11] = ctime(&forstat.st_mtime)[15];
        current_time_zone[12] = ctime(&forstat.st_mtime)[16];
        current_time_zone[13] = ctime(&forstat.st_mtime)[17];
        current_time_zone[14] = ctime(&forstat.st_mtime)[18];
        current_time_zone[15] = ctime(&forstat.st_mtime)[19];
        current_time_zone[16] = ctime(&forstat.st_mtime)[20];
        current_time_zone[17] = ctime(&forstat.st_mtime)[21];
        current_time_zone[18] = ctime(&forstat.st_mtime)[22];
        current_time_zone[19] = ctime(&forstat.st_mtime)[23];
    } 
    else {
        current_time_zone = mx_strnew(12);
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
    }
    mx_printstr(current_time_zone);
    free(current_time_zone);
}
