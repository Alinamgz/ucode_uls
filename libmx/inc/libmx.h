#pragma once

// ===================== defines ======================
// buffer size for read()
#define BUFFER_SIZE 64

// ===================== includes =====================
#include <fcntl.h>
#include <limits.h>
#include <malloc/malloc.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

// ===================== structs ======================

typedef struct s_calcul {
    unsigned long number;
    unsigned long quot;
    int rem;
    int size;
    int base;
}              t_calcul;

typedef struct s_bin_search {
    int left;
    int right;
    int mid;
    int comp;
}              t_bin_search;

typedef struct s_file_to_str {
    int src_fd;
    char* dst;
    char* result;
    char buff[BUFFER_SIZE + 1];
    ssize_t src_rslt;
}              t_file_to_str;

typedef struct s_strsplit {
    char **rslt;
    char *buf_s;
    int w_cnt;
    int w_len;
    int i;
}              t_strsplit;


typedef struct s_list {
    void *data;
    struct s_list *next;
}              t_list;

typedef struct s_for_replsub {
    char *sub_pnt;
    int sub_len;
    int repl_len;
    int rslt_len;
    int str_i;
    int rslt_i;
}              t_for_replsub;

// ===================== functions ====================

// ---------------------- UTILS ----------------------
char *mx_itoa(int number);
char *mx_nbr_to_hex(unsigned long nbr);

double mx_pow(double n, unsigned int pow);

int mx_binary_search(char **arr, int size, const char *s, int *count);
int mx_bubble_sort(char **arr, int size);
int mx_sqrt(int x);
int mx_quicksort(char **arr, int left, int right);

unsigned long mx_hex_to_nbr(const char *hex);

void mx_foreach(int *arr, int size, void (*f)(int));
void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
void mx_print_strarr(char **arr, const char *delim);
void mx_print_unicode(wchar_t c);

// ---------------------- STRING ----------------------
char *mx_del_extra_spaces(const char *str);
char *mx_itoa(int number);
char *mx_file_to_str(const char *file);
char *mx_replace_substr(const char *str, const char *sub, const char *replace);
char *mx_strcat(char *restrict s1, const char *restrict s2);
char *mx_strcpy(char *dst, const char *src);
char *mx_strdup(const char *s1);
char *mx_strndup(const char *s1, size_t n);
char *mx_strjoin(char const *s1, char const *s2);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strnew(const int size);
char **mx_strsplit(const char *s, char c);
char *mx_strstr(const char *haystack, const char *needle);
char *mx_strtrim(const char *str);

int mx_count_substr(const char *str, const char *sub);
int mx_count_words(const char *str, char delimiter);
int mx_get_char_index(const char *str, char c);
int mx_get_substr_index(const char *str, const char *sub);
int mx_strcmp(const char *s1, const char *s2);
int mx_strlen(const char *s);

void mx_del_strarr(char ***arr);
void mx_strdel(char **str);
void mx_str_reverse(char *s);
void mx_swap_char(char *s1, char *s2);

// ---------------------- MEMORY ----------------------
int mx_memcmp(const void *s1, const void *s2, size_t n);

void *mx_memchr(const void *s, int c, size_t n);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *mx_memccpy(void *restrict dst,
                 const void *restrict src,
                 int c,
                 size_t n);
 void *mx_memmem(const void *big,
                size_t big_len,
                const void *little,
                size_t little_len
                );
void *mx_memset(void *b, int c, size_t len);
void *mx_memrchr(const void *s, int c, size_t n);
void *mx_memmove(void *dst, const void *src, size_t len);
void *mx_realloc(void *ptr, size_t size);

// ---------------------- LIST ------------------------
int mx_list_size(t_list *list);

t_list *mx_create_node(void *data);
t_list *mx_sort_list(t_list *list, bool (*cmp)(void *, void *));

void mx_pop_back(t_list **list);
void mx_pop_front(t_list **list);
void mx_push_back(t_list **list, void *data);
void mx_push_front(t_list **list, void *data);

// ---------------------- OPTIONAL --------------------
bool mx_isalpha(int c);
bool mx_isdigit(int c);
bool mx_islower(int c);
bool mx_isspace(char c);
bool mx_isupper(int c);

char *mx_concat_words(char **words);
char *mx_strchr(const char *s, int c);

int mx_atoi(const char *str);
int mx_check_substr(const char *src, const char *sub);
int mx_factorial_iter(int n);
int mx_gcd(int a, int b);
int mx_lcm(int a, int b);
int mx_strlen_nullcheck(const char *s);
int mx_tolower(int c);
int mx_toupper(int c);

t_for_replsub *mx_set_struct(const char *str,const char *sub, const char *repl);

unsigned long mx_mod(int num);

void mx_only_printable(void);
void mx_print_arr_int(const int *arr, int size);
void mx_printerr(const char *s);
