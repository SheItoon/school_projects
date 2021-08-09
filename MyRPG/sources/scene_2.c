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

scene_t *scene_create(sfVector2f rsize, sfVector2i frag)
{
    scene_t *scene = 0;

    scene = malloc(sizeof(scene_t));
    scene->size = frag;
    scene->region_data = list_create(MB_FRECT);
    scene->reg_side = map_create(10, MB_ROBJ);
    scene->obj_refs = list_create(MB_ROBJ);
    fill_rlist(scene, rsize);
    return (scene);
}

void scene_free(scene_t **pscene)
{
    scene_t *scene = (pscene == 0) ? 0 : *pscene;
    iterator_t it;

    if (pscene == 0 || *pscene == 0)
        return;
    it = list_begin(scene->obj_refs);
    for (; !list_final((scene->obj_refs), it); it = it_next(it))
        obj_free(list_pull(scene->obj_refs, it));
    list_free(&scene->region_data);
    list_free(&scene->obj_refs);
    map_free(&scene->reg_side);
    free(scene);
    *pscene = 0;
}

sfFloatRect get_object_bounds(robject_t const *obj)
{
    for (uint_t i = 0; !is_rom_empty(ROM_ARRAY + i); i++) {
        if (obj->type == ROM_ARRAY[i].type)
            return (ROM_ARRAY[i].m_bgetter(obj->ptr));
    }
    return (sfFloatRect){0, 0, 0, 0};
}

hash_value_t qh_obj(robject_t const *obj)
{
    return (hash_data(obj, sizeof(robject_t)));
}

hash_value_t qh_rect(sfFloatRect const *rect)
{
    return (hash_data(rect, sizeof(sfFloatRect)));
}
