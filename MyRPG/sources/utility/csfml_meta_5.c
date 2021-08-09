/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** csfml_meta.c
*/
#include "csfml_meta.h"

sfFloatRect sfsprite_getgbounds(void const *ptr)
{
    return (sfSprite_getGlobalBounds(ptr));
}

sfFloatRect sfcshape_getgbounds(void const *ptr)
{
    return (sfCircleShape_getGlobalBounds(ptr));
}

sfFloatRect sfrshape_getgbounds(void const *ptr)
{
    return (sfRectangleShape_getGlobalBounds(ptr));
}

sfFloatRect sfxshape_getgbounds(void const *ptr)
{
    return (sfConvexShape_getGlobalBounds(ptr));
}

sfFloatRect sftext_getgbounds(void const *ptr)
{
    return (sfText_getGlobalBounds(ptr));
}
