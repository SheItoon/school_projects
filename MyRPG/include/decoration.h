/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#ifndef DECORATION_H_INCLUDED
#define DECORATION_H_INCLUDED

#include <SFML/Graphics.h>
#include "istl/common_types.h"
#include "scene.h"
#include "animation.h"

extern const mdata_t MB_DECOR;

typedef struct Decoration (decor_t);

decor_t *decor_create(bool_t dynamic);
void decor_free(decor_t **);
void decor_destroy(void *);
void *decor_copy(void const *);
void decor_update(void *, sfTime, scene_t *);

void decor_set_sprite(decor_t *, sfSprite const *);
void decor_set_zoffset(decor_t *, float);
void decor_set_position(decor_t *, sfVector2f);
void decor_set_height(decor_t *, uint_t);
void decor_draw(sfRenderWindow *, void const *, sfRenderStates const *); 
sfFloatRect decor_getgbounds(void const *);
void decor_set_animation(decor_t *, animf_t *);

#endif
