/*
** EPITECH PROJECT, 2021
** init
** File description:
** init
*/

#include <stdlib.h>
#include <string.h>
#include "nm.h"

info_t *init(char **av)
{
    info_t *tmp = malloc(sizeof(info_t));

    if (tmp == NULL)
        return (NULL);
    memset(tmp, 0, sizeof(info_t));
    tmp->name = av[0];
    return (tmp);
}
