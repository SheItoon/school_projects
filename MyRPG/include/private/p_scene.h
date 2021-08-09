/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef PRIVATE_SCENE_H_INCLUDED
#define PRIVATE_SCENE_H_INCLUDED

#include "scene.h"

struct RenderObjectMeta {
    /*! \brief Type of render object to associate with stored methods
    */
    rotype_t type;

    /*! \brief Type's drawing function
    */
    void (*m_draw)(sfRenderWindow *, void const *, sfRenderStates const *);

    /*! \brief Type's update function
    */
    void (*m_update)(void *, sfTime, scene_t *);

    /*! \brief Type's global bounds' getter
    */
    sfFloatRect (*m_bgetter)(void const *);
};

extern const struct RenderObjectMeta ROM_ARRAY[];

void fill_rlist(scene_t *scene, sfVector2f rsize);
sfFloatRect get_object_bounds(robject_t const *obj);
hash_value_t qh_obj(robject_t const *obj);
hash_value_t qh_rect(sfFloatRect const *rect);
void assign_region(scene_t *scene, robject_t obj);
void unlink_region(scene_t *sc, robject_t obj);
void adjust_rect(scene_t *sc, list_t *objs, sfFloatRect rect);
void obj_update(robject_t obj, scene_t *scene, sfTime delta);
void objs_update(list_t *objs, scene_t *scene, sfTime delta);
void obj_draw(sfRenderWindow *window, robject_t *obj, rstates_t *states);
void objs_draw(sfRenderWindow *window, list_t *objs, rstates_t *states);
void objs_sort(scene_t *scene);
void filter_objs(list_t *objs, rotype_t type);
destructor_ft get_obj_destructor(rotype_t t);
bool_t is_rom_empty(struct RenderObjectMeta const *);
bool_t ro_sorter(iterator_t lhs, iterator_t rhs);

#endif
