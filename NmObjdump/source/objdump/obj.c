/*
** EPITECH PROJECT, 2021
** objd
** File description:
** bodj
*/

#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include "objdump.h"
#include "obj_utils.h"

static int obj_files(obj_t *obj, int ac, char **av)
{
    if (obj == NULL)
        return (84);
    return (objdumps(obj, ac, av));
}

static int obj_file(obj_t *obj, char *str)
{
    if (obj == NULL || str == NULL)
        return (84);
    obj->finfo.name = str;
    return (objdump(obj));
}

static int obj_single(obj_t *obj)
{
    if (obj == NULL)
        return (84);
    obj->finfo.name = "a.out";
    return (objdump(obj));
}

static void *init(char *str)
{
    obj_t *tmp = malloc(sizeof(obj_t));

    if (tmp == NULL)
        return (NULL);
    memset(tmp, 0, sizeof(obj_t));
    tmp->name = str;
    return (tmp);
}

int obj_engine(int ac, char **av)
{
    obj_t *obj = init(av[0]);
    int ret = 84;

    if (obj == NULL)
        return (84);
    switch (ac) {
    case 1: ret = obj_single(obj);
        clear(obj);
        return (ret);
    case 2: ret = obj_file(obj, av[1]);
        clear(obj);
        return (ret);
    default: ret = obj_files(obj, ac, av);
        clear(obj);
        return (ret);
    }
}
