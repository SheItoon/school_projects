/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** return size of string
*/

#include "my_hunter.h"

int my_strlen(char const *str)
{
    unsigned int size = 0;

    if (str == NULL)
        return (0);
    while (*str) {
        size += 1;
        str += 1;
    }
    return (size);
}
