/*
** EPITECH PROJECT, 2019
** nextline lib
** File description:
** lib
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef READ_SIZE
#define READ_SIZE (30)
#endif

#ifndef _GET_NEXT_LINE_
#define _GET_NEXT_LINE_

typedef struct params
{
    char *buff;
    int bytes;
    int start;
} params_s;

typedef struct result
{
    int check;
    char *res;
    char *newres;
    int oldsize;
} res_s;
char *get_next_line(int fd);
#endif
