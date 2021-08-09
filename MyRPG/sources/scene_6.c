/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include "private/p_scene.h"
#include "creature.h"
#include "csfml_meta.h"
#include "decoration.h"

const struct RenderObjectMeta ROM_ARRAY[] = {
    {
        .type = RO_CREATURE,
        .m_draw = creature_draw,
        .m_update = creature_update,
        .m_bgetter = creature_getgbounds
    },
    {
        .type = RO_VARRAY,
        .m_draw = sfvarray_draw,
        .m_update = NULL,
        .m_bgetter = sfvarray_getgbounds
    },
    {
        .type = RO_TEXT,
        .m_draw = sftext_draw,
        .m_update = NULL,
        .m_bgetter = sftext_getgbounds
    },
    {
        .type = RO_SPRITE,
        .m_draw = sfsprite_draw,
        .m_update = NULL,
        .m_bgetter = sfsprite_getgbounds
    },
    {
        .type = RO_XSHAPE,
        .m_draw = sfxshape_draw,
        .m_update = NULL,
        .m_bgetter = sfxshape_getgbounds
    },
    {
        .type = RO_CSHAPE,
        .m_draw = sfcshape_draw,
        .m_update = NULL,
        .m_bgetter = sfcshape_getgbounds
    },
    {
        .type = RO_RSHAPE,
        .m_draw = sfrshape_draw,
        .m_update = NULL,
        .m_bgetter = sfcshape_getgbounds
    },
    {
        .type = RO_DECOR,
        .m_draw = decor_draw,
        .m_update = decor_update,
        .m_bgetter = decor_getgbounds
    },
    {RO_LEVEL, NULL, NULL, NULL}
};

bool_t ro_sorter(iterator_t lhs, iterator_t rhs)
{
    sfFloatRect bds1;
    sfFloatRect bds2;

    bds1 = get_object_bounds(it_data(lhs));
    bds2 = get_object_bounds(it_data(rhs));
    if (bds1.top + bds1.height > bds2.top + bds2.height)
        return (TRUE);
    return (FALSE);
}

void objs_sort(scene_t *scene)
{
    if (scene == NULL)
        return;
    list_sort(scene->obj_refs, ro_sorter);
}

bool_t is_rom_empty(struct RenderObjectMeta const *rom)
{
    bool_t res = TRUE;

    if (rom == NULL)
        return (FALSE);
    res = (rom->m_draw == NULL) ? res : FALSE;
    res = (rom->m_update == NULL) ? res : FALSE;
    res = (rom->m_bgetter == NULL) ? res : FALSE;
    return (res);
}
