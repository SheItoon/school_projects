/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#ifndef PRIVATE_SCHEME_H_INCLUDED
#define PRIVATE_SCHEME_H_INCLUDED

#include "scheme.h"

typedef struct GridScheme {
    uint_t tsize;
    uint_t width;
    uint_t height;
    int **tiles;
    decor_t *(*translator)(const struct GridScheme *, int);
} (scheme_t);

int scheme_loadobj(scheme_t const *, scene_t *, sfVector2f, int);

decor_t *deco_door(int val);
decor_t *deco_desk(int val);
decor_t *deco_box(int val);
decor_t *deco_lamp(int val);
decor_t *deco_pic(int val);
decor_t *deco_subj(int val);
decor_t *deco_locker(int val);
decor_t *deco_chair(int val);
decor_t *deco_wall(int val);

#endif
