/*
** EPITECH PROJECT, 2021
** DISP_PRIVATE_H
** File description:
** display_private
*/

#ifndef DISP_PRIVATE_H
#define DISP_PRIVATE_H

#include "ftrace.h"
#include <stdarg.h>

#define ARR_SIZE (40)

typedef struct signal_s
{
    int sig_code;
    char *to_string;
} signal_t;

// disp_api.c
bool is_authorized_flag(char flag);

// load_from_register.c
char *read_str(user_input_t usr, unsigned long long reg);
char **read_str_array(user_input_t usr, unsigned long long reg);

#endif /* DISP_PRIVATE_H */

