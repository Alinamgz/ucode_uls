#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
   int i;
   int s1_leng = mx_strlen(s1);
   
   for (i = 0; s2[i] !='\0' ; i++) {
        s1[s1_leng + i]  = s2[i];
   }
   s1[s1_leng + i] = '\0';

   return(char *) s1;
}
