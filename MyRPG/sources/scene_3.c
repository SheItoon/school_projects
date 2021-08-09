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

void assign_region(scene_t *scene, robject_t obj)
{
    iterator_t it;
    sfFloatRect rect;
    sfFloatRect ob = get_object_bounds(&obj);
    list_t *list = 0;

    if (scene == 0 || obj.sprite == 0)
        return;
    it = list_begin(scene->region_data);
    for (; !list_final(scene->region_data, it); it = it_next(it)) {
        rect = *(sfFloatRect *)list_data(it);
        if (sfFloatRect_intersects(&ob, &rect, 0)) {
            map_erase(scene->reg_side,
                    qh_rect(&rect), hash_data(&obj, sizeof(obj)));
            map_insert(scene->reg_side, qh_rect(&rect), &obj);
        }
    }
    return;
}

void scene_link(scene_t *scene, robject_t obj)
{
    assign_region(scene, obj);
    list_push_back(scene->obj_refs, &obj);
}

void unlink_region(scene_t *sc, robject_t obj)
{
    sfFloatRect bds = get_object_bounds(&obj);
    sfFloatRect rbds;
    iterator_t it;
    hash_value_t ohash = hash_data(&obj, sizeof(obj));
    hash_value_t rhash;

    if (sc == 0)
        return;
    it = list_begin(sc->region_data);
    for (; !list_final(sc->region_data, it); it = it_next(it)) {
        rbds = *(sfFloatRect*)it_data(it);
        rhash = hash_data(&rbds, sizeof(sfFloatRect));
        if (sfFloatRect_intersects(&rbds, &bds, 0))
            map_erase(sc->reg_side, rhash, ohash);
    }
}

void scene_unlink(scene_t *scene, rotype_t type, void *data)
{
    iterator_t it;
    robject_t obj;

    if (scene == 0 || data == 0)
        return;
    it = list_begin(scene->obj_refs);
    for (; !list_final(scene->obj_refs, it); it = it_next(it)) {
        obj = *(robject_t *)it_data(it);
        if (obj.sprite == data) {
            unlink_region(scene, obj);
            obj_free(list_pull(scene->obj_refs, it));
        }
    }
}

hash_value_t scene_linko(scene_t *scene, rotype_t type, void *data)
{
    robject_t obj;
    list_t *list = 0;

    if (scene == 0 || data == 0)
        return (0);
    obj.type = type;
    obj.sprite = data;
    scene_link(scene, obj);
    return (0);
}
