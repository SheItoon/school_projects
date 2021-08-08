/*
** EPITECH PROJECT, 2021
** type
** File description:
** type
*/

#pragma once
#include "strace_define.h"

enum arg_type_e {
    INT,
    PTR,
    STR
};

typedef struct entry_s
{
    const char *name;
    int nb_args;
    enum arg_type_e args_value[SYSCALL_MAXARGS];
    enum arg_type_e retval;
} entry_t;
