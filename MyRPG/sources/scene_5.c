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

void obj_free(robject_t *obj)
{
    destructor_ft destr;

    if (obj == 0)
        return;
    destr = get_obj_destructor(obj->type);
    if (destr != 0)
        destr(obj->sprite);
}

void scene_update(scene_t *scene, sfTime delta)
{
    iterator_t rit;
    list_t *violators = 0;
    sfFloatRect rect;
    hash_value_t rhash;
    list_t *objs = 0;

    if (scene == 0)
        return;
    objs_update(scene->obj_refs, scene, delta);
    objs_sort(scene);
    rit = list_begin(scene->region_data);
    for (; !list_final(scene->region_data, rit); rit = it_next(rit)) {
        rect = *(sfFloatRect *)list_data(rit);
        rhash = hash_data(&rect, sizeof(sfFloatRect));
        objs = map_get_all(scene->reg_side, rhash);
        adjust_rect(scene, objs, rect);
        list_free(&objs);
    }
}

void obj_draw(sfRenderWindow *window, robject_t *obj, rstates_t *states)
{
    if (window == NULL || obj == NULL)
        return;
    for (uint_t i = 0; !is_rom_empty(ROM_ARRAY + i); i++) {
        if (obj->type == ROM_ARRAY[i].type && ROM_ARRAY[i].m_draw != NULL)
            ROM_ARRAY[i].m_draw(window, obj->ptr, states);
    }
}

void objs_draw(sfRenderWindow *window, list_t *objs, rstates_t *states)
{
    iterator_t it;
    robject_t *obj = 0;

    if (objs == 0)
        return;
    it = list_begin(objs);
    for (; !list_final(objs, it); it = it_next(it)) {
        obj = list_data(it);
        obj_draw(window, obj, states);
    }
}

void scene_draw(sfRenderWindow *window, scene_t *scene, sfRenderStates *states)
{
    iterator_t it;
    list_t *list = 0;

    it = list_begin(scene->obj_refs);
    for (; !list_final(scene->obj_refs, it); it = it_next(it))
        obj_draw(window, it_data(it), states);
}
