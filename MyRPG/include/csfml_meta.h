/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** csfml_meta.h
*/

#ifndef CSFML_META_H_INCLUDED
#define CSFML_META_H_INCLUDED

#include <SFML/Graphics.h>
#include <stdlib.h>

void *sftexture_pcopy(void const *data);
void sftexture_pdestroy(void *data);
void *sfsprite_pcopy(void const *data);
void sfsprite_pdestroy(void *data);
void sfrshape_pdestroy(void *data);
void sfcshape_pdestroy(void *data);
void sfvarray_pdestroy(void *data);
void sfxshape_pdestroy(void *data);
void sftext_pdestroy(void *data);
void *sffont_pcopy(void const *data);
void sffont_pdestroy(void *);

void sfsprite_draw(sfRenderWindow *, void const *, sfRenderStates const *);
void sfcshape_draw(sfRenderWindow *, void const *, sfRenderStates const *);
void sfrshape_draw(sfRenderWindow *, void const *, sfRenderStates const *);
void sfxshape_draw(sfRenderWindow *, void const *, sfRenderStates const *);
void sfvarray_draw(sfRenderWindow *, void const *, sfRenderStates const *);
void sftext_draw(sfRenderWindow *, void const *, sfRenderStates const *);

sfFloatRect sfsprite_getgbounds(void const *);
sfFloatRect sfcshape_getgbounds(void const *);
sfFloatRect sfrshape_getgbounds(void const *);
sfFloatRect sfxshape_getgbounds(void const *);
sfFloatRect sfvarray_getgbounds(void const *);
sfFloatRect sftext_getgbounds(void const *);

#endif
