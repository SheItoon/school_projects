/*
** EPITECH PROJECT, 2020
** display_help
** File description:
** help
*/

#include "my_world.h"

char *get_buffer(char const *str, int size)
{
    char *tmp = malloc(sizeof(char) * (size + 1));
    int temp = open(str, O_RDONLY);

    read(temp, tmp, size);
    tmp[size] = '\0';
    close(temp);
    return (tmp);
}

int get_sizehelp(char const *str)
{
    int tmp = open(str, O_RDONLY);
    int i;
    char *buffer = malloc(sizeof(char) * 1);

    for (i = 0; read(tmp, buffer, 1); i++);
    close(tmp);
    free(buffer);
    return (i);
}

void display_help(void)
{
    int size = get_sizehelp("help");
    char *buffer = get_buffer("help", size);

    write(1, buffer, size);
}
