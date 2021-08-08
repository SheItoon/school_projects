/*
** EPITECH PROJECT, 2021
** free
** File description:
** free
*/

#include "libmemory.h"
#include <stdio.h>
#include <stdlib.h>

static void handle_previous(chunk_t *chunk)
{
    chunk_t *previous;

    if (chunk->previous && chunk->previous->freed) {
        previous = chunk->previous;
        previous->next = chunk->next;
        previous->offset += chunk->offset + sizeof(chunk_t);
        if (chunk->next)
            chunk->next->previous = previous;
        if (memory_handle(CURRENT, GET, NULL) == chunk)
            memory_handle(CURRENT, SET, previous);
    }
}

static void handle_next(chunk_t *chunk)
{
    chunk_t *next;

    if (chunk->next && chunk->next->freed) {
        next = chunk->next;
        chunk->next = next->next;
        chunk->offset += next->offset + sizeof(chunk_t);
        if (chunk->next)
            chunk->next->previous = chunk;
        if (memory_handle(CURRENT, GET, NULL) == next)
            memory_handle(CURRENT, SET, chunk);
    }
}

static void handle_current(void)
{
    chunk_t *tmp;

    if (memory_handle(CURRENT, GET, NULL)->freed) {
        memory_handle(HEAD, SET, (memory_handle(CURRENT, GET, NULL)
        == memory_handle(HEAD, GET, NULL)) ? NULL :
        memory_handle(HEAD, GET, NULL));
        tmp = memory_handle(CURRENT, GET, NULL);
        memory_handle(CURRENT, SET,
        memory_handle(CURRENT, GET, NULL)->previous);
        if (memory_handle(CURRENT, GET, NULL))
            memory_handle(CURRENT, GET, NULL)->next = NULL;
        sbrk(-(tmp->offset + sizeof(chunk_t)));
    }
}

void free(void *ptr)
{
    chunk_t *chunk;

    if (!ptr)
        return;
    if (memory_handle(HEAD, GET, NULL) == NULL)
        fprintf(stderr, "Invalide Free\n"), abort();
    chunk = (chunk_t *)((char *)ptr - sizeof(chunk_t));
    if (chunk && chunk->freed)
        fprintf(stderr, "Invalid Free\n"), abort();
    chunk->freed = true;
    handle_next(chunk);
    handle_previous(chunk);
    handle_current();
}
