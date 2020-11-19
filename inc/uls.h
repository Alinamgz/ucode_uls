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
#include "libmx.h"

// ====== structs ======
typedef struct s_parce {
    char *flags;
    bool *flags_state;
    char *target;
    char **addresses;
    char **files;
    char **dirs;
    char **invalid;
}              t_parse;

typedef struct s_direct {
    char **content_of_directory;
    int count_of_objects;
}              t_direct;

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
void mx_sort_addresses (t_parse *);


void list_directory(t_direct *direct);
void output_ls(t_parse *p, t_direct *direct);
void list_longdir(const char *path);
int directory_info(t_direct *direct);
void print_in_line(t_direct *direct, int first_ln);
void line_output(t_direct *direct);
void lexicographical_sort(t_direct *direct);
void print_in_multiline(t_direct *direct, int first_ln, struct winsize size_wind);
