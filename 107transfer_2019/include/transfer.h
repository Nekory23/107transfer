/*
** EPITECH PROJECT, 2019
** 107transfer
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>
#include <math.h>
#include <string.h>

typedef struct coef
{
    char **str_a;
    char **str_b;
    int *tab_a;
    int *tab_b;
    double res_a;
    double res_b;
    double res;
    int max_a;
    int max_b;
} coef_t;

int my_strcmp(char const *str1, char const *str2);
void write_error(char *str);

void help_display(void);
int error_handling(int ac, char **av);

int start(int ac, char **av);
void compute(coef_t *co, int ac, char **av);

int count(char *str);
char **my_split(char *src);
coef_t *fill_struct(coef_t *co, char **av);
coef_t *fill_sec_struct(coef_t *co, char *arg1, char *arg2);

int check_div(coef_t *co, int ac, char **av);

#define SUCCESS 0
#define ERROR 84
#define FALSE 0
#define TRUE 1

#define STR_HELP "(see with -h)\n"
#define STR_ERROR_ARGNBR "this program must take at least 3 arguments "
#define STR_ERROR_STRING "one or more of the strings are incorrect "
#define STR_ERROR_DEN "there must be the same number of NUM and DEN "
#define STR_ERROR_DIV "error : division by 0\n"

#endif
