/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** resource_loaders.c
*/

#include "scheme.h"
#include "resource_loaders.h"
#include "read_map.h"

const sfIntRect TXT_FLOOR[] = {
    {0, 0, 233 * 7, 233 * 5},
    {0, 0, 233 * 4, 1855},
    {0, 0, 233 * 13, 233 * 11},
    {233 * 4, 233 * 9, 233 * 7, 233 * 2}
};

int load_resources(void)
{
    int res = 0;

    res += rl_load_sounds();
    res += rl_load_textures();
    res += rl_load_animations();
    res += rl_load_fonts();
    return (res);
}

int rl_load_sounds(void)
{
    return (0);
}

int rl_load_textures(void)
{
    int res = 0;

    rload_texture("./resources/textures/rpg_floor.png",
            "fw_tileset", &TXT_FLOOR[0]);
    rload_texture("./resources/textures/rpg_hero.png",
            "main_hero", &TXT_FLOOR[1]);
    rload_texture("./resources/textures/rpg_furniture.png",
            "deco_tileset", &TXT_FLOOR[2]);
    rload_texture("./resources/textures/rpg_furniture.png",
            "subject", &TXT_FLOOR[3]);
    res += rlt_creatures();
    return (0);
}

int rl_load_animations(void)
{
    int res = 0;

    res += rla_creatures();
    return (0);
}
