/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include "istl/shared_ptr.h"
#include "private/p_decoration.h"
#include "utility.h"

const mdata_t MB_DECOR = (mdata_t) {
    .copy = decor_copy,
    .destroy = decor_destroy,
    .data_size = sizeof(decor_t)
};

decor_t *decor_create(bool_t dynamic)
{
    decor_t *decor = shared_ptr(MB_DECOR);

    decor->dynamic = dynamic;
    decor->height = 0;
    decor->sprite = NULL;
    decor->in_state = sfSeconds(0);
    decor->state = 0;
    decor->anim = NULL;
    decor->z_offset = 0;
    return (decor);
}

void decor_free(decor_t **decor_p)
{
    if (decor_p == NULL || *decor_p == NULL)
        return;
    spdestroy(*decor_p);
    *decor_p = NULL;
}

void decor_destroy(void *decor_p)
{
    decor_t *decor = decor_p;

    if (decor_p == NULL)
        return;
    if (decor->sprite != NULL)
        sfSprite_destroy(decor->sprite);
}

void *decor_copy(void const *decor_p)
{
    decor_t const *decor = decor_p;
    decor_t *copy = NULL;

    if (decor == NULL)
        return (NULL);
    copy = shared_ptr(MB_DECOR);
    copy->dynamic = decor->dynamic;
    copy->sprite = (decor->sprite == NULL) ?
        NULL : sfSprite_copy(decor->sprite);
    copy->height = decor->height;
    return (copy);
}

void decor_set_position(decor_t *decor, sfVector2f vec)
{
    if (decor == NULL || decor->sprite == NULL)
        return;
    sfSprite_setPosition(decor->sprite, vec);
}
