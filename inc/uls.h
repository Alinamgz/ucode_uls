#pragma once

#include "../libmx/inc/libmx.h"

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

int list_directory();
int list_longdir(const char *path);
bool gitignore (char *argv[]);
