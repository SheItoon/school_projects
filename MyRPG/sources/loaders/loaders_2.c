/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** loaders_2.c
*/
#include "resource_loaders.h"

int rl_load_fonts(void)
{
    int res = 0;

    rload_font("resources/fonts/Bellota-Regular.ttf", "bellota");
    rload_font("resources/fonts/Montserrat-Regular.ttf", "montserrat");
    return (res);
}
