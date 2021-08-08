/*
** EPITECH PROJECT, 2021
** utils
** File description:
** utils
*/

#include <stdio.h>
#include <sys/mman.h>
#include "objdump.h"

int out_of_map(obj_t *obj, void *addr, size_t len)
{
    return (!(obj->finfo.vadress <= addr &&
    (char *)addr + len <= (char *)obj->finfo.vadress + obj->finfo.size));
}

int my_munmap(obj_t *obj, int ret)
{
    if (obj->finfo.vadress)
        munmap(obj->finfo.vadress, obj->finfo.size);
    return (ret);
}

int objserror(obj_t *obj, char const *str)
{
    if (obj)
        fprintf(stderr, "%s: '%s': ", obj->name, obj->finfo.name);
    fprintf(stderr, "%s\n", str);
    return (84);
}

int objerror(obj_t *obj, char const *str)
{
    if (obj)
        fprintf(stderr, "%s: %s: ", obj->name, obj->finfo.name);
    fprintf(stderr, "%s\n", str);
    return (84);
}

int my_strlen(void *ptr, char c, int max)
{
    char *str = ptr;
    int i;

    for (i = 0; (max == -1 || i < max) && str[i] != c && str[i]; i++);
    return (i);
}
