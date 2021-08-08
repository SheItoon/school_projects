/*
** EPITECH PROJECT, 2021
** utils
** File description:
** utils
*/

#include "nm.h"
#include <glob.h>
#include <ctype.h>
#include <stdlib.h>
#include <elf.h>
#include "print.h"

static int contain(char c, char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return (1);
    return (0);
}

int my_strlen(void *ptr, char c, int max)
{
    char *str = ptr;
    int i;

    for (i = 0; (i < max || max == -1) && str[i] && str[i] != c; i++);
    return (i);
}

int my_strcmp(char *a, char *b)
{
    size_t i;
    size_t j = 0;

    for (i = 0; a[i] && b[j]; i++, j++) {
        for (; contain(a[i], "_."); i++);
        for (; contain(b[j], "_."); j++);
        if (tolower(a[i]) != tolower(b[j]))
            break;
    }
    if (tolower(a[i]) - tolower(b[j]) == 0)
        return ((int)(j - i));
    return (tolower(a[i]) - tolower(b[j]));
}

void clear(info_t *info)
{
    if (info == NULL)
        return;
    free(info);
}

int loop_type(info_t *info, list_t n)
{
    if (info->finfo.arch == ELFCLASS64) {
        if (print_type64(info, n) == 84)
            return (84);
    } else
        if (print_type32(info, n) == 84)
            return (84);
    return (0);
}
