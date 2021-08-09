/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** csfml_types.c
*/

#include "csfml_types.h"
#include "csfml_meta.h"

const meta_bundle_t MB_IRECT = {
    0,
    0,
    sizeof(sfIntRect)
};
const meta_bundle_t MB_TEXTURE = {
    sftexture_pcopy,
    sftexture_pdestroy,
    sizeof(sfTexture*)
};
const meta_bundle_t MB_SPRITE = {
    sfsprite_pcopy,
    sfsprite_pdestroy,
    sizeof(sfSprite*)
};
const meta_bundle_t MB_SFVEC = {
    0,
    0,
    sizeof(sfVector2f)
};
const meta_bundle_t MB_FONT = {
    sffont_pcopy,
    sffont_pdestroy,
    sizeof(sfVector2f)
};
