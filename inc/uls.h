#pragma once

// ====== defines ======
#define VALID_FLAGS "l"
#define L_FLAGS "h@eT"

// ---- error msg -------
#define ILLEGAL_OPTION "uls: illegal option -- "
#define USAGE_START "\nusage: uls [-"
#define USAGE_END "] [file ...]\n"
#define ULS "uls: "
#define ADDR_ERR ": No such file or directory\n"

// ====== includes ======
#include <sys/types.h>
#include <sys/acl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <stdbool.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/xattr.h>
#include "libmx.h"

// ====== structs ======
typedef struct s_parce {
    bool *flags_state;
    char *flags;
    char *target;
    char **addresses;
    char **files;
    char **dirs;
    char **ivalid_addr;
    char **content_of_directory;
    int count_of_objects;
    int count_of_files;
}              t_parse;

typedef struct s_forlong {
    int *max_len;
}              t_forlong;

// ======= funcs =======
// int mx_parse_input(int argc, char **argv, t_parse *p);
// int list_directory(char *path);
// int output_ls(t_parse *p);
// int list_longdir(const char *path);
void mx_init_parsing (t_parse *p);
void mx_parse_input(int argc, char **argv, t_parse *p);
int mx_parse_flags(int argc, char **argv, t_parse *p);
void mx_parse_addresses(int i, int argc, char **argv, t_parse *p);
void mx_sort_alphabetically(char **arr, int left, int right);


void list_directory(t_parse *p, char *path);
void output_ls(t_parse *p, char *path);
void list_longdir(char *path, t_forlong *forlong, t_parse *p);
int directory_info(t_parse *p, char *path);
void print_in_line(t_parse *p, int first_ln);
void line_output(t_parse *p);
void lexicographical_sort(t_parse *p);
void print_in_multiline(t_parse *p, int first_ln, struct winsize size_wind);
void list_few_filedirs(t_parse *p, char *path);
void mx_sort_addresses(t_parse *p);
void list_files(t_parse *p);
void count_max_len(t_parse *p, t_forlong *forlong);
void print_lnumber(int value, int max_len);
void print_time(struct stat forstat);
void mx_get_acl_xattr(char *path);
void print_lname(char *name, int max_len);
void list_few_longdirs(char *path, t_forlong *forlong, t_parse *p);
void list_longfile(t_forlong *forlong, t_parse *p);
void count_maxlen_files(t_parse *p, t_forlong *forlong);
