/*
** EPITECH PROJECT, 2021
** ftrace
** File description:
** disp_engine
*/

#include "display_private.h"
#include "display.h"
#include "ftrace.h"
#include <string.h>
#include <stdio.h>
#include "tools.h"
#include <stdarg.h>

inline bool is_authorized_flag(char flag)
{
    register size_t ctr = -1;
    const char authorized_flags[NB_AUTHORIZED_FLAGS] = AUTHORIZED_FLAGS;

    while (++ctr < NB_AUTHORIZED_FLAGS) {
        if (flag == authorized_flags[ctr])
            return true;
    }
    return false;
}

