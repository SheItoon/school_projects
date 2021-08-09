/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** resource_loaders.h
*/
#ifndef RESOURCE_LOADERS_H_INCLUDED
#define RESOURCE_LOADERS_H_INCLUDED

#include "animation.h"
#include "resource_holder.h"

/*!
    \brief Loads all the resources needed for the game
*/
int load_resources(void);

/*!
    \brief Loads all the needed sounds
*/
int rl_load_sounds(void);

/*!
    \brief Loads all the needed textures
*/
int rl_load_textures(void);
int rlt_creatures(void);

/*!
    \brief Loads all the needed animations
*/
int rl_load_animations(void);
int rla_creatures(void);
int rlac_alexa(void);

/*!
    \brief Loads all the needed fonts
*/
int rl_load_fonts(void);

#endif
