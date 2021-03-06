/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "istl/private/p_vector.h"

vector_t *vector_push(vector_t *vec, void const *cdata)
{
    if (vec == NULL)
        return (NULL);
    if (vec->size == vec->capacity)
        vector_expand(vec);
    vec->size += 1;
    vector_set(vec, vec->size - 1, cdata);
    return (vec);
}

uint_t vector_expand(vector_t *vec)
{
    void **data = NULL;

    if (vec == NULL)
        return (0);
    vec->capacity *= 2;
    data = malloc(sizeof(void *) * vec->capacity);
    for (uint_t i = 0; i < vec->capacity; i++)
        data[i] = (i < vector_len(vec)) ? vec->data[i] : NULL;
    free(vec->data);
    vec->data = data;
    return (vec->capacity);
}

int vector_iswap(vector_t *vec, uint_t idx1, uint_t idx2)
{
    void *data = NULL;

    if (vec == NULL || NMAX(idx1, idx2) >= vector_len(vec))
        return (-1);
    data = vec->data[idx1];
    vec->data[idx1] = vec->data[idx2];
    vec->data[idx2] = data;
    return (0);
}

void vector_sort(vector_t *vec, vsorter_ft sorter)
{
    uint_t len = vector_len(vec);

    if (vec == NULL || sorter == NULL || len < 2)
        return;
    vector_qs(vec, sorter, 0, len - 1);
}

void vector_qs(vector_t *vec, vsorter_ft sorter, uint_t lb, uint_t rb)
{
    uint_t li = lb;
    uint_t ri = rb - 1;
    uint_t m = (lb + rb) / 2;
    void const *const p = vector_cget(vec, m);

    int pid;

    if (vec == NULL || lb >= rb)
        return;
    vector_iswap(vec, rb, m);
    vector_qs(vec, sorter, lb, (li > 0) ? li - 1 : 0);
    vector_qs(vec, sorter, li + 1, rb);
}
