/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** scene.h
*/
#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include <SFML/Graphics.h>
#include "istl/common_types.h"
#include "istl/list.h"
#include "istl/hash_table.h"

extern const meta_bundle_t MB_FRECT;
extern const meta_bundle_t MB_ROBJ;
extern const meta_bundle_t MB_HASH;

typedef sfRenderStates (rstates_t);
typedef struct Creature (creature_t);
typedef struct tower_s (tower_t);
typedef struct level_s (level_t);

/*!
    \brief Possible render object stored data enum
*/
typedef enum ROBJECT_TYPE {
    RO_SPRITE, //!< sfSprite
    RO_XSHAPE, //!< sfConvexShape
    RO_CSHAPE, //!< sfCircleShape
    RO_RSHAPE, //!< sfRectangleShape
    RO_TEXT,
    RO_VARRAY,  //!< sfVertexArray
    RO_CREATURE,
    RO_SHOT,
    RO_LEVEL,
    RO_DECOR
} rotype_t;

/*!
    \brief Universal bundle to store any registered graphical object
    \details This bundle allows to create a container that could
    contain any **[enumerated](@ref ROBJECT_TYPE)** data type
*/
typedef struct RenderObject {
    rotype_t type;  //!< Stored data type
    union {
        sfSprite *sprite;
        sfConvexShape *xshape;
        sfCircleShape *cshape;
        sfRectangleShape *rshape;
        sfVertexArray *varray;
        sfText *text;
        creature_t *creature;
        void *ptr;
    };
} (robject_t);

void obj_free(robject_t *obj);

/*!
    \brief The actual entity printed on screen
    \details While this entity allows to minimize interactions
    with the application's window, it also allows to organize
    data and filter entities by zones. The scene allows you to
    retrieve a list of **[objects](@ref RenderObject)** that could
    possibly collide with another object.
    \bug Added objects' sprites don't refresh on scene's render
    stage. Probably a copy is made somewhere, that points to wrong
    sprite or smth.
*/
typedef struct Scene {
    list_t *region_data; //!< Linked list of all sub-regions of the scene
    list_t *obj_refs;
    sfVector2i size;    //!< Size vector of the scene
    map_t *reg_side;    //!< HashMap with regions linkes to objects
} scene_t;

/*!
    \brief Scene main constructor
    \details Creates a scene with defined rendered size and fragmentation
    \see [scene_free](@ref scene_free)
    \param rsize Desired rendered size
    \param frag Fragmentation vector
    \return Allocated scene
    \todo Test
*/
scene_t *scene_create(sfVector2f rsize, sfVector2i frag);

/*!
    \brief Scene freeing function
    \details This functions destroys the entire scene and free the memory.
    **Beware**: NO DEEP FREE performed, since the scene only refers
    to objects, but is not responsible for them
    \param scene Pointer to target scene pointer
    \see scene_create
    \see scene_destroy
    \todo Test
*/
void scene_free(scene_t **scene);

/*!
    \brief Puts the object's reference into the scene
    \details This function will store the object's reference into
    the scene to draw it on screen every time the scene itself
    is drawn
    \param scene Target scene
    \param obj Target obj pointer wrapper
    \see RenderObject
    \see scene_pull
    \todo Test and reduce (21 lines)
*/
void scene_link(scene_t *scene, robject_t obj);

void scene_unlink(scene_t *scene, rotype_t type, void *);

hash_value_t scene_linko(scene_t *scene, rotype_t type, void *);

list_t *scene_get_near(scene_t *scene, sfFloatRect rect, rotype_t);
list_t *scene_get_anear(scene_t *scene, sfFloatRect rect);

robject_t *scene_get_at(scene_t *scene, sfVector2f vec);
robject_t *scene_get_tat(scene_t *scene, rotype_t type, sfVector2f vec);

/*!
    \brief Draw the scene with all this content on the screen
    \param window Application's window
    \param scene Target scene
    \param states Render states to apply to the entire scene
*/
void scene_draw(sfRenderWindow *window, scene_t *scene, sfRenderStates *states);

void scene_update(scene_t *scene, sfTime delta);

void scene_pull(scene_t *scene, robject_t obj);

#endif
