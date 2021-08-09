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

void fill_rlist(scene_t *scene, sfVector2f rsize)
{
    sfVector2f ratio;
    sfFloatRect rect = (sfFloatRect){0, 0, 0, 0};

    ratio.x = rsize.x / (float)scene->size.x;
    ratio.y = rsize.y / (float)scene->size.y;
    rect.width = ratio.x;
    rect.height = ratio.y;
    for (int i = 0; i < scene->size.y; i++)
        for (int j = 0; j < scene->size.x; j++) {
            rect.left = j * ratio.x;
            rect.top = i * ratio.y;
            list_push_back(scene->region_data, &rect);
        }
}

void adjust_rect(scene_t *sc, list_t *objs, sfFloatRect rect)
{
    iterator_t it;
    sfFloatRect bds;
    robject_t obj;
    hash_value_t rhash = hash_data(&rect, sizeof(rect));
    hash_value_t ohash;
    void *ptr = NULL;

    if (objs == 0)
        return;
    it = list_begin(objs);
    for (; !list_final(objs, it); it = it_next(it)) {
        obj = *(robject_t *)it_data(it);
        ohash = hash_data(&obj, sizeof(obj));
        bds = get_object_bounds(&obj);
        if (sfFloatRect_intersects(&rect, &bds, 0) == sfFalse) {
            free(map_erase(sc->reg_side, rhash, ohash));
            assign_region(sc, obj);
        }
    }
}

void obj_update(robject_t obj, scene_t *scene, sfTime delta)
{
    for (uint_t i = 0; !is_rom_empty(ROM_ARRAY + i); i++)
        if (obj.type == ROM_ARRAY[i].type)
            if (ROM_ARRAY[i].m_update != NULL)
                ROM_ARRAY[i].m_update(obj.ptr, delta, scene);
}

void objs_update(list_t *objs, scene_t *scene, sfTime delta)
{
    iterator_t it;
    robject_t obj;

    if (objs == 0)
        return;
    for (it = list_begin(objs); !list_final(objs, it); it = it_next(it)) {
        obj = *(robject_t *)it_data(it);
        obj_update(obj, scene, delta);
    }
}

destructor_ft get_obj_destructor(rotype_t t)
{
    destructor_ft f = 0;

    f = (t == RO_SPRITE) ? sfsprite_pdestroy : f;
    f = (t == RO_XSHAPE) ? sfxshape_pdestroy : f;
    f = (t == RO_CSHAPE) ? sfcshape_pdestroy : f;
    f = (t == RO_RSHAPE) ? sfrshape_pdestroy : f;
    f = (t == RO_VARRAY) ? sfvarray_pdestroy : f;
    f = (t == RO_TEXT) ? sftext_pdestroy : f;
    f = (t == RO_CREATURE) ? creature_destroy : f;
    return (f);
}
