/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>

#include "istl/shared_ptr.h"
#include "istl/private/p_vector.h"

const mdata_t MB_VECTOR = (mdata_t) {
    .copy = vector_copy,
    .destroy = vector_destroy,
    .data_size = sizeof(vector_t)
};

vector_t *vector_create(mdata_t type)
{
    vector_t *vec = shared_ptr(MB_VECTOR);

    vec->size = 0;
    vec->capacity = 1;
    vec->tmeta = type;
    vec->data = malloc(sizeof(void *) * vec->capacity);
    return (vec);
}

void vector_free(vector_t **vec_p)
{
    if (vec_p == NULL || (*vec_p) == NULL)
        return;
    spdestroy(*vec_p);
    (*vec_p) = NULL;
}

void *vector_copy(void const *vec_p)
{
    vector_t *copy = NULL;
    vector_t const *vec = vec_p;
    void **data = NULL;

    if (vec_p == NULL)
        return (NULL);
    copy = shared_ptr(MB_VECTOR);
    copy->tmeta = vec->tmeta;
    copy->size = 0;
    copy->capacity = vec->capacity;
    copy->data = malloc(sizeof(void *) * copy->capacity);
    for (uint_t i = 0; i < vector_len(vec); i++)
        vector_push(copy, vector_cget(vec, i));
    return (copy);
}

void *vector_pull(vector_t *vec, uint_t idx)
{
    void *data = NULL;

    if (vec == NULL)
        return (NULL);
    data = vector_get(vec, idx);
    if (data != NULL)
        vector_set(vec, idx, NULL);
    return (data);
}

vector_t *vector_pop(vector_t *vec)
{
    void *data = NULL;

    if (vec == NULL)
        return (NULL);
    data = vector_pull(vec, vector_len(vec) - 1);
    vec->size -= 1;
    if (vec->tmeta.destroy != NULL)
        vec->tmeta.destroy(data);
    else
        free(data);
    return (vec);
}
