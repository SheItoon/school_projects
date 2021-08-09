/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** scene.c
*/

#include <stdlib.h>
#include "private/p_scene.h"
#include "creature.h"
#include "csfml_meta.h"

const meta_bundle_t MB_FRECT = {0, 0, sizeof(sfFloatRect)};
const meta_bundle_t MB_ROBJ = {0, 0, sizeof(robject_t)};
const meta_bundle_t MB_HASH = {0, 0, sizeof(hash_value_t)};

void filter_objs(list_t *objs, rotype_t type)
{
    iterator_t it;
    robject_t obj;

    if (objs == 0)
        return;
    it = list_begin(objs);
    for (; !list_final(objs, it); it = it_next(it)) {
        obj = *(robject_t *)it_data(it);
        if (obj.type != type)
            free(list_pull(objs, it));
    }
}

list_t *scene_get_near(scene_t *scene, sfFloatRect rect, rotype_t type)
{
    list_t *objs = 0;

    objs = scene_get_anear(scene, rect);
    filter_objs(objs, type);
    return (objs);
}

list_t *scene_get_anear(scene_t *scene, sfFloatRect rect)
{
    iterator_t it;
    sfFloatRect *zone = 0;
    hash_value_t zhash;
    list_t *objs = 0;
    list_t *tmp = 0;

    it = list_begin(scene->region_data);
    for (uint_t i = 0; i < list_len(scene->region_data); i++) {
        zone = (sfFloatRect*)it_data(it);
        if (sfFloatRect_intersects(zone, &rect, 0)) {
            zhash = hash_data(zone, sizeof(*zone));
            tmp = (list_t *)map_get_all(scene->reg_side, zhash);
            objs = (objs == 0 && tmp != 0) ? list_create(MB_ROBJ) : objs;
            list_merge(objs, tmp);
        }
        it = it_next(it);
    }
    return (objs);
}

robject_t *scene_get_at(scene_t *scene, sfVector2f vec)
{
    sfFloatRect bds = (sfFloatRect) {vec.x - 1, vec.y - 1, 2, 2};
    list_t *objs = 0;
    iterator_t it;

    if (scene == 0)
        return (0);
    objs = scene_get_anear(scene, bds);
    if (objs == NULL)
        return (NULL);
    it = list_begin(objs);
    for (; !list_final(objs, it); it = it_next(it)) {
        bds = get_object_bounds(it_data(it));
        if (sfFloatRect_contains(&bds, vec.x, vec.y))
            return (it_data(it));
    }
    return (0);
}

robject_t *scene_get_tat(scene_t *scene, rotype_t type, sfVector2f vec)
{
    sfFloatRect bds = (sfFloatRect){vec.x - 1, vec.y - 1, 2, 2};
    list_t *objs = 0;
    iterator_t it;
    rotype_t otype;

    if (scene == 0)
        return (0);
    objs = scene_get_anear(scene, bds);
    it = list_begin(objs);
    for (; !list_final(objs, it); it = it_next(it)) {
        otype = ((robject_t *)it_data(it))->type;
        if (otype != type)
            continue;
        bds = get_object_bounds(it_data(it));
        if (sfFloatRect_contains(&bds, vec.x, vec.y))
            return (it_data(it));
    }
    return (0);
}
