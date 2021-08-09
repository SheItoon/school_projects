/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** gjk.h
*/
#ifndef GJK_H_INCLUDED
#define GJK_H_INCLUDED

#include <SFML/Graphics.h>

typedef sfVertexArray (varray_t);

/*!
    \brief Support point searching function
    \details This function takes all the vertex points of a convex shape
    and returns the furthest point in given direction
    \todo lelou
*/
sfVector2f gjk_support(varray_t *, sfVector2f);

#endif
