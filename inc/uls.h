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
}

// ======= funcs =======
