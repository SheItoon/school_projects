/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** resource_holder.h
*/

#ifndef RESOURCE_HOLDER_H_INCLUDED
#define RESOURCE_HOLDER_H_INCLUDED

#include <SFML/Graphics.h>
#include "istl/common_types.h"
#include "istl/hash_table.h"

#include "animation.h"

typedef struct HashMap rholder_t;

sfTexture *rget_texture(cchar_t);
int rload_texture(cchar_t filename, cchar_t name, sfIntRect const *rect);
int rload_animation(animf_t const *anim, cchar_t name);
animf_t *rget_animation(cchar_t name);

int rload_font(cchar_t filename, cchar_t name);
sfFont *rget_font(cchar_t name);

#endif
