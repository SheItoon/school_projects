/*
** EPITECH PROJECT, 2021
** calloc
** File description:
** calloc
*/

#include "libmemory.h"
#include <string.h>

void *calloc(size_t nmemb, size_t size)
{
    void *tmp = malloc(nmemb * size);

    if (tmp == NULL)
        return (NULL);
    memset(tmp, 0, nmemb * size);
    return (tmp);
}
