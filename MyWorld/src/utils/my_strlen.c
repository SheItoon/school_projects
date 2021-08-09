/*
** EPITECH PROJECT, 2020
** str
** File description:
** str
*/

#include "my_world.h"

int my_strlen(char *str)
{
    int i;

    if (str == NULL)
        return (-1);
    for (i = 0; str[i]; i++);
    return (i);
}
