/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** creature.h
*/

#ifndef CREATURE_H_INCLUDED
#define CREATURE_H_INCLUDED

#include <SFML/Graphics.h>
#include "istl/common_types.h"
#include "istl/list.h"

extern const meta_bundle_t MB_CREATURE;
typedef struct Scene (scene_t);
typedef struct tower_s (tower_t);

typedef enum CREATURE_MOVE_STATE {
    CM_UP,
    CM_DOWN,
    CM_RIGHT,
    CM_LEFT,
    CM_STAND
} cm_state_t;

typedef enum DMG_EFFECT {DE_SLOW, DE_SHOCK} effect_tt;

typedef struct CreatureStats {
    int defense;
} cstats_t;

/*!
    \brief Interactive dynamic living entity class
    \details Creature object encapsulates a creature in-game
    logic representation, containing its graphical
    part and various associated variables to manipulate
    them more easily. Data within a creature **MUST NEVER**
    be accessed directly from external functions, since
    it could mess up with associated methods. All the
    interface methods assume this data is **NEVER** accessed
    from any other function, process or whatever.
    \author Iaroslav Sorokin
*/
typedef struct Creature {
    uint_t health;
    double speed;
    sfVector2f velo;
    list_t *path;
    list_t *subscribers;
    sfSprite *sprite;
    sfRenderStates states;
    sfShader *shader;
    uint_t hovered;
    cm_state_t mstate;
    sfTime in_state;
    uint_t height;
} creature_t;

void creature_subscribe(creature_t *cr, tower_t *tower);

/*!
    **Main creature constructor**: returns an allocated
    object with assigned health points and speed.
    Automatically detects values errors, and returns
    0 if couldn't manage to allocate memory.
*/
creature_t *creature_create(uint_t hp, double speed);

/*!
    **Main creature destructor**: Makes the deep free
    of following data fields:
    - sprite
    - shader
    Also sets the given pointer to NULL.
    \todo Erase shader initialisation
*/
void creature_free(creature_t **pcreature);

/*!
    Copy constructor, follows the required by **list_t**
    and **map_t** API. That's why it accepts a constant
    void pointer and returns one. This interface is a
    necessary thing to store and (indirectly) destroy
    the object in a data structure. Doesn't provide any
    data type detection mechanism, be careful when
    calling.
*/
void *creature_copy(void const *pcreature);

/*!
    Creature API destroyer. Relies upon **creature_free**,
    serves to give an API to this data structure for the
    containers capable of storing multiple types.
*/
void creature_destroy(void *pcreature);

/*!
    Enables hover status of the creature for several
    game ticks (render ticks).
*/
void creature_set_tick_hover(creature_t *pcreature, uint_t tick_count);

/*!
    Sprite setter method. Allocates a newcopy of the given
    sprite, so feel free to erase your copy. Please don't set ANY data
    via direct access to the structure: it could cause
    undesired behaviour (such as a SEGFAULT).
*/
void creature_set_sprite(creature_t *pcreature, sfSprite const *sprite);

/*!
    \brief Tells a creature to move to a certain point
    \todo Write new doc
    \startuml
    participant Creature as creature
    == Some place in code ==
    [-> creature: **Move at (x, y)**
    activate creature
    alt No current direction
        creature -> creature: Update direction
        note right
            It is the direction vector (only) that
            tells a creature that it has to move
            while the **update** phase
        end note
    else Already has a direction
        creature -> creature: Update current path
        note left
            Puts the new point at the end of the
            current path list, that will be choosed
            right after first one is reached
        end note
    end
    deactivate creature
    == Creature update phase ==
    [-> creature: **Update**
    activate creature
    creature -> creature: **Update position**
    group Position update
        creature -> creature: Move linked sprite
        creature -> creature: Test if reached current point
        alt Point reached
            creature -> creature: Pull reached point
            note right: Erases first point from the path
            creature -> creature: Update direction vector
        end
    end
    creature -> creature: **Update state**
    creature -> creature: **Update animation**
    deactivate creature
    \enduml
*/
void creature_move_at(creature_t *pcreature, sfVector2f destination);

/*!
    Main update method: **NO ACTION IS PERFORMED** without
    calling this, every single creature's action is updated
    here every game tick. Be aware of that.
*/
void creature_update(void *pcreature, sfTime delta, scene_t *scene);

/*!
    Predicate method that allows the clien to know if a creature
    is in the moving state (Thus being moved every single tick).
*/
bool_t creature_moves(creature_t const *pcreature);

void creature_deal_dmg(creature_t *creature, uint_t dmg);

void creature_apply_effect(creature_t *creature, effect_tt effect);

cstats_t creature_get_stats(creature_t const *creature);

sfFloatRect creature_getgbounds(void const *creature);

sfVector2f creature_get_position(creature_t const *creature);

/*!
    SFML API method that gives better syntax for creature drawing
    and allows to add some logic in the process. Shaders and
    immediate transformations should be applyied here.
    \bug States application is buggy
*/
void creature_draw(sfRenderWindow *, void const *, sfRenderStates const *);
void creature_fill_pass(creature_t *cr);
creature_t *gen_monster(uint_t hp, double speed);

#endif
