/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** csfml_meta.c
*/
#include "csfml_meta.h"

void sfsprite_draw(
        sfRenderWindow *w,
        void const *varray_p,
        sfRenderStates const *st)
{
    sfRenderWindow_drawSprite(w, varray_p, st);
}

void sfcshape_draw(
        sfRenderWindow *w,
        void const *varray_p,
        sfRenderStates const *st)
{
    sfRenderWindow_drawCircleShape(w, varray_p, st);
}

void sfrshape_draw(
        sfRenderWindow *w,
        void const *varray_p,
        sfRenderStates const *st)
{
    sfRenderWindow_drawRectangleShape(w, varray_p, st);
}

void sfxshape_draw(
        sfRenderWindow *w,
        void const *varray_p,
        sfRenderStates const *st)
{
    sfRenderWindow_drawConvexShape(w, varray_p, st);
}

void sftext_draw(
        sfRenderWindow *w,
        void const *varray_p,
        sfRenderStates const *st)
{
    sfRenderWindow_drawText(w, varray_p, st);
}
