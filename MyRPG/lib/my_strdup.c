/*
** EPITECH PROJECT, 2019
** dup
** File description:
** ezfeffz
*/

#include <stdlib.h>

int my_strlen(char const*);
char *my_strcpy(char*, char const*);

char *my_strdup(char const *src)
{
    char* dest;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    my_strcpy(dest, src);
    return (dest);
}
