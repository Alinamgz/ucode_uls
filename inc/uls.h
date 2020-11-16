#pragma once

// ====== defines ======
#define HELLO_MSG "Hello World!\n"

// ====== includes ======
#include "libmx.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>


// ====== structs ======
typedef struct s_parce {
    char *flags;
    char **addresses;
}               t_parse;flage

// ======= funcs =======
void mx_parse_input(int argc, char **argv, t_parse *p);
