#pragma once

// ====== defines ======
#define HELLO_MSG "Hello World!\n"

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
    char *flags;
    char **addresses;
}               t_parse;

// ======= funcs =======
int mx_parse_input(int argc, char **argv, t_parse *p);
int list_directory(char *path);
int output_ls(t_parse *p);
int list_longdir(const char *path);
