/*
** EPITECH PROJECT, 2021
** handler
** File description:
** handler
*/

#include "libmemory.h"

chunk_t *process_list(chunk_t *list, action_e action, chunk_t *value)
{
    chunk_t *tmp = list;

    switch (action) {
    case GET:
        return (tmp);
    case SET:
        list = value;
        break;
    }
    return (NULL);
}

chunk_t *memory_handle(list_e list, action_e action, chunk_t *value)
{
    static chunk_t *start = NULL;
    static chunk_t *current = NULL;

    switch (list) {
    case HEAD:
        switch (action) {
        case SET: start = value;
            break;
        case GET: return (start);
        }
        break;
    case CURRENT:
        switch (action) {
        case SET: current = value;
            break;
        case GET: return (current);
        }
        break;
    }
    return (NULL);
}

size_t pagesize_handler(action_e action, size_t value)
{
    static size_t pagesize = 0;

    switch (action) {
    case SET:
        pagesize = value;
        break;
    case GET:
        return (pagesize);
    }
    return (0);
}
