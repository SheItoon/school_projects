/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc
*/

#include "libmemory.h"

static void create_chunk(chunk_t *chunk, size_t offset)
{
    chunk->next = NULL;
    chunk->previous = memory_handle(CURRENT, GET, NULL);
    chunk->offset = offset;
    chunk->freed = false;
    if (memory_handle(CURRENT, GET, NULL))
        memory_handle(CURRENT, GET, NULL)->next = chunk;
    memory_handle(CURRENT, SET, chunk);
}

static chunk_t *break_chunk(chunk_t *chunk, size_t offset)
{
    chunk_t *new;
    int check = (int)(chunk->offset - (offset + sizeof(chunk_t)));

    if (check >= 8) {
        new = (chunk_t *)((char*)chunk + sizeof(chunk_t) + offset);
        new->previous = chunk;
        new->next = chunk->next;
        new->offset = chunk->offset - (offset + sizeof(chunk_t));
        new->freed = true;
        if (chunk->next)
            chunk->next->previous = new;
        chunk->next = new;
        chunk->offset = offset;
        if (memory_handle(CURRENT, GET, NULL) == chunk)
            memory_handle(CURRENT, SET, new);
    }
    chunk->freed = false;
    return (chunk);
}

static void handle_chunk(chunk_t *chunk, size_t offset, size_t size)
{
    create_chunk(chunk, offset);
    chunk->offset = size - sizeof(chunk_t);
    chunk = break_chunk(chunk, offset);
}

static chunk_t *get_chunk_new(size_t offset)
{
    chunk_t *chunk = NULL;
    chunk_t *tmp = memory_handle(HEAD, GET, NULL);
    size_t size;

    for (; !chunk && tmp; tmp = tmp->next)
        if (tmp->offset >= offset && tmp->freed)
            chunk = break_chunk(tmp, offset);
    if (!chunk) {
        size = (sizeof(chunk_t) + offset - 1) / pagesize_handler(GET, 0)
        * pagesize_handler(GET, 0) + pagesize_handler(GET, 0);
        chunk = sbrk(size);
        if (chunk == (void *)-1)
            return (NULL);
        else
            handle_chunk(chunk, offset, size);
    }
    memory_handle(HEAD, SET, (!memory_handle(HEAD, GET, NULL)) ? chunk
    : memory_handle(HEAD, GET, NULL));
    return (chunk);
}

void *malloc(size_t size)
{
    chunk_t *chunk;

    if (!pagesize_handler(GET, 0))
        pagesize_handler(SET, getpagesize());
    size = (size <= 0) ? 8 : size;
    size = convert_paging(size);
    chunk = get_chunk_new(size);
    return ((char *)chunk + sizeof(chunk_t));
}
