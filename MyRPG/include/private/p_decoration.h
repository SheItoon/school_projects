/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#ifndef PRIVATE_DECORATION_H_INCLUDED
#define PRIVATE_DECORATION_H_INCLUDED

#include "decoration.h"

typedef struct Decoration {
    bool_t dynamic;
    sfSprite *sprite;
    uint_t height;
    sfTime in_state;
    int state;
    animf_t *anim;
    float z_offset;
} (decor_t);

#endif
