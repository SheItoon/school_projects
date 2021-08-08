/*
** EPITECH PROJECT, 2021
** realloc
** File description:
** realloc
*/

#include "libmemory.h"
#include <string.h>

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    size_t check;

    if (__builtin_mul_overflow(nmemb, size, &check))
        return (NULL);
    return (realloc(ptr, check));
}

void *realloc(void *ptr, size_t size)
{
    chunk_t *chunk;
    void *tmp;

    if (!ptr)
        return (malloc(size));
    if (!size)
        return (free(ptr), NULL);
    chunk = (chunk_t *)((char *)ptr - sizeof(chunk_t));
    if (chunk->freed)
        return (NULL);
    if (chunk->offset >= convert_paging(size))
        return (ptr);
    tmp = malloc(size);
    if (tmp)
        memcpy(tmp, (char *)chunk + sizeof(chunk_t), chunk->offset);
    return (free(ptr), tmp);
}
