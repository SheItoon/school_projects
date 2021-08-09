/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include "istl/utility.h"
#include "istl/shared_ptr.h"
#include "resource_holder.h"
#include "p_scheme.h"

const mdata_t MB_SCHEME = (mdata_t) {
    .copy = scheme_copy,
    .destroy = scheme_destroy,
    .data_size = sizeof(scheme_t)
};

const sfVector2f VEC_DICT[T_CONCRETE - T_EMPTY + 1] = {
    {1, 4},
    {0, 1},
    {3, 1},
    {2, 1},
    {4, 1},
    {1, 1},
    {4, 2},
    {6, 2},
    {5, 3},
    {6, 3},
    {5, 2},
    {4, 3},
    {5, 1},
    {3, 2},
    {4, 0},
    {5, 0},
    {6, 0},
    {1, 0},
    {0, 0},
    {2, 0},
    {5, 1},
    {6, 1},
    {0, 2},
    {1, 2},
    {0, 3},
    {1, 3},
    {4, 3},
    {2, 3},
    {2, 2},
};

scheme_t *scheme_create(int **data, uint_t w, uint_t h)
{
    scheme_t *scheme = NULL;

    if (data == NULL || w < 1 || h < 1)
        return (NULL);
    scheme = shared_ptr(MB_SCHEME);
    scheme->tiles = data;
    scheme->tsize = 233;
    scheme->width = w;
    scheme->height = h;
    scheme->translator = scheme_translate;
    return (scheme);
}

void scheme_free(scheme_t **scheme_p)
{
    if (scheme_p == NULL || *scheme_p == NULL)
        return;
    spdestroy(*scheme_p);
    (*scheme_p) = NULL;
}

void scheme_destroy(void *scheme_p)
{
    scheme_t *scheme = scheme_p;

    if (scheme_p == NULL)
        return;
    free(scheme->tiles);
}

void *scheme_copy(void const *scheme_p)
{
    scheme_t *copy = NULL;
    scheme_t const *scheme = scheme_p;
    int **data = NULL;

    if (scheme_p == NULL)
        return (NULL);
    data = malloc(sizeof(int *) * scheme->height);
    for (uint_t i = 0; i < scheme->height; i++) {
        data[i] = malloc(sizeof(int) * scheme->width);
        for (uint_t j = 0; j < scheme->width; j++)
            data[i][j] = scheme->tiles[i][j];
    }
    copy = scheme_create(data, scheme->width, scheme->height);
    if (copy == NULL) {
        for (uint_t i = 0; i < scheme->height; i++)
            free(data[i]);
        return (free(data), NULL);
    }
    copy->tsize = scheme->tsize;
    return (copy);
}

decor_t *scheme_translate(scheme_t const *scheme, int val)
{
    decor_t *decor = NULL;
    sfSprite *sp = NULL;
    sfVector2f vec = {0, 0};
    uint_t size;

    if (scheme == NULL)
        return (NULL);
    size = scheme->tsize;
    vec = VEC_DICT[val];
    decor = decor_create(FALSE);
    sp = sfSprite_create();
    sfSprite_setTexture(sp, rget_texture("fw_tileset"), sfTrue);
    sfSprite_setTextureRect(sp,
            (sfIntRect) {vec.x * size, vec.y * size, size, size});
    decor_set_sprite(decor, sp);
    sfSprite_destroy(sp);
    return (decor);
}
