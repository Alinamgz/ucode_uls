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
#include "libmx.h"

// ====== structs ======
typedef struct s_parce {
    int right;
    char *flags;
    bool *flags_state;
    char *l_flags;
    char *target;
    char **addresses;
    char **files;
    char **dirs;
    char **ivalid_addr;
}              t_parse;

// ======= funcs =======
// int mx_parse_input(int argc, char **argv, t_parse *p);
// int list_directory(char *path);
// int output_ls(t_parse *p);
// int list_longdir(const char *path);
void mx_init_parsing (t_parse *p);
void mx_parse_input(int argc, char **argv, t_parse *p);
void mx_validate_flags(t_parse *p);
void mx_sort_addr(t_parse *p);
int mx_parse_flags(int argc, char **argv, t_parse *p);
void mx_parse_addresses(int i, int argc, char **argv, t_parse *p);

void list_directory(char *path);
void output_ls(t_parse *p);
void list_longdir(const char *path);
