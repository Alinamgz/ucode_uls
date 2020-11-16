#include "libmx.h"

void mx_del_strarr(char ***arr) {
  char **runner = NULL;
  
  if(arr) {
    runner = *arr;
    while(*runner) {
        mx_strdel(runner) ;
        runner++;
    }
    free(*arr);
    *arr = NULL;
  }
}
