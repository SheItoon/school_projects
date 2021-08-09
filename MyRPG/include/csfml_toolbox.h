/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef CSFML_TOOLBOX_H_INCLUDED
#define CSFML_TOOLBOX_H_INCLUDED

#include <SFML/Graphics.h>
#include "istl/common_types.h"

#include <stdio.h>

/*!
    Add 2 SFML vectors
*/
#define V_ADD(lhs, rhs) \
    do { \
        (lhs).x += (rhs).x; \
        (lhs).y += (rhs).y; \
    } while (0)

/*!
    Subtract 2 SFML vectors
*/
#define V_SUB(lhs, rhs) \
    do { \
        (lhs).x -= (rhs).x; \
        (lhs).y -= (rhs).y; \
    } while (0)
/*!
    Multiply 2 SFML vectors
*/
#define V_MUL(lhs, rhs) \
    do { \
        (lhs).x *= (rhs); \
        (lhs).y *= (rhs); \
    } while (0)

/*!
    Returns the dot product of 2 given SFML vectors
*/
#define V_DOT(lhs, rhs) \
    (double)((lhs).x*(rhs).x+(lhs).y*(rhs).y)

/*!
    Returns absolute value of a number
*/
#define ABS(value) \
    ((value) < 0) ? 0 - (value) : (value)

/*!
    Returns maximum value between two
*/
#define MAX(lhs, rhs) \
    (lhs) > (rhs) ? (lhs) : (rhs)

#define T_ADD(lhs, rhs) \
    (lhs).microseconds += (rhs).microseconds

#define T_SUB(lhs, rhs) \
    (lhs).microseconds -= (rhs).microseconds

#define T_MOD(lhs, rhs) \
    (lhs).microseconds %= (rhs).microseconds

/*!
    \brief Serves to init ```sfRenderStates``` to default value
*/
sfRenderStates get_default_rstates(void);

/*!
    \brief Allows to compare 2 ```sfTime``` objects
*/
bool_t sfTime_gt(sfTime lhs, sfTime rhs);

/*!
    \brief Allows to subtract 2 ```sfTime``` objects
*/
sfTime sfTime_sub(sfTime lhs, sfTime rhs);

/*!
    \brief Allows to add 2 ```sfTime``` objects
*/
sfTime sfTime_add(sfTime lhs, sfTime rhs);

#endif
