/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** cevent.h
*/

#ifndef CUSTOM_EVENT_H_INCLUDED
#define CUSTOM_EVENT_H_INCLUDED

#include <SFML/Graphics.h>

typedef struct level_s (level_t);
typedef struct Creature (creature_t);

/*!
    \brief Hovered sprite related data
*/
struct SpriteHoverEvent {
    sfSprite *sprite;   //!< A pointer to the hovered sprite
};

/*!
    \brief Hovered creature related data
*/
struct CreatureHoverEvent {
    creature_t *ptr;    //!< Pointer at the hovered creature
};

/*!
    \brief Different possible internal event types
*/
typedef enum MD_EVENT_TYPE {
    MD_SPRITE_HOVERED,      //!< Hovered sprite
    MD_CREATURE_HOVERED,    //!< Hovered creature
    MD_TOWER_CREATED        //!< Tower created
} mdevent_type_t;

/*!
    \brief Custom bundle with all event related data
    \details Data bundle passed to an event handler when
    an event is raised by the application. It simmulates
    the exact same principle as an ```sfEvent``` type,
    and can be manipulated in the same manner. Beware that
    as for SFML, event related data is stored in structures,
    contained in the **exact same** memory space, so if
    your type gessing is wrong, you could end up operating
    on corrupted data.
    \author Iaroslav Sorokin
*/
typedef struct CustomEvent {
    mdevent_type_t type;    //!< \brief Event type
    union {
        struct SpriteHoverEvent sprite_hovered;
        struct CreatureHoverEvent creature_hovered;
    };
} mdevent_t;

#endif
