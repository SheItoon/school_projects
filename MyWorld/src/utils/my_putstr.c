/*
** EPITECH PROJECT, 2020
** e
** File description:
** e
*/

#include "my_world.h"

void my_putstr(char *str)
{
    int size = my_strlen(str);

    write(1, str, size);
}
