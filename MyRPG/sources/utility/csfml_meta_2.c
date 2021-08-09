/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** csfml_meta.c
*/

#include "csfml_meta.h"

void *sftexture_pcopy(void const *data)
{
    sfTexture *ptxt = (sfTexture*)data;

    return (sfTexture_copy(ptxt));
}

void sftexture_pdestroy(void *data)
{
    sfTexture *ptxt = (sfTexture*)data;

    sfTexture_destroy(ptxt);
}

void *sfsprite_pcopy(void const *data)
{
    sfSprite *pspr = (sfSprite*)data;

    return (sfSprite_copy(pspr));
}

void sfsprite_pdestroy(void *data)
{
    sfSprite *pspr = (sfSprite*)data;

    sfSprite_destroy(pspr);
}

void sfrshape_pdestroy(void *data)
{
    if (data == 0)
        return;
    sfRectangleShape_destroy(data);
}
