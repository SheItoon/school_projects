/*
** EPITECH PROJECT, 2021
** ftrace
** File description:
** str_funcs
*/

#include "tools.h"

char *get_last(char *string, char needle)
{
    if (!string)
        return 0x0;
    for (int i = 0; string[i] != 0; i++)
        if (string[i] == needle)
            return get_last(&string[i + 1], needle);
    return string;
}

