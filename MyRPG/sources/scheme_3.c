/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "resource_holder.h"
#include "p_scheme.h"

const sfIntRect DOOR_DICT[] = {
    {233 * 0, 233 * 0, 233 * 2, 233 * 2},
    {233 * 2, 233 * 0, 233 * 2, 233 * 2},
    {233 * 4, 233 * 0, 233 * 2, 233 * 2},
    {233 * 6, 233 * 0, 233 * 2, 233 * 2},
    {233 * 8, 233 * 0, 233 * 2, 233 * 2},
    {233 * 10, 233 * 0, 233 * 1, 233 * 2},
    {233 * 11, 233 * 0, 233 * 1, 233 * 2},
    {233 * 12, 233 * 0, 233 * 1, 233 * 2},
};

const sfIntRect BOX_DICT[] = {
    {233 * 7, 233 * 1, 233 * 1, 233 * 2},
    {233 * 8, 233 * 1, 233 * 1, 233 * 2},
    {233 * 9, 233 * 1, 233 * 1, 233 * 2},
    {233 * 11, 233 * 1, 233 * 1, 233 * 1},
    {233 * 11, 233 * 2, 233 * 1, 233 * 1},
    {233 * 12, 233 * 1, 233 * 1, 233 * 1},
};

const sfIntRect LAMP_DICT[] = {
    {233 * 0, 233 * 4, 233 * 1, 233 * 1},
    {233 * 1, 233 * 4, 233 * 1, 233 * 1},
    {233 * 2, 233 * 4, 233 * 1, 233 * 1},
    {233 * 3, 233 * 4, 233 * 1, 233 * 1},
};

const sfIntRect DESK_DICT[] = {
    {233 * 4, 233 * 4, 233 * 2, 233 * 1},
    {233 * 6, 233 * 4, 233 * 2, 233 * 1},
    {233 * 8, 233 * 6, 233 * 2, 233 * 1},
    {233 * 0, 233 * 5, 233 * 2, 233 * 2},
    {233 * 2, 233 * 5, 233 * 2, 233 * 2},
    {233 * 4, 233 * 5, 233 * 2, 233 * 2},
    {233 * 6, 233 * 5, 233 * 2, 233 * 2},
    {233 * 3, 233 * 7, 233 * 2, 233 * 2},
    {233 * 5, 233 * 7, 233 * 2, 233 * 2},
    {233 * 7, 233 * 7, 233 * 2, 233 * 2},
    {233 * 9, 233 * 7, 233 * 2, 233 * 2},
};

const sfIntRect PIC_DICT[] = {
    {233 * 12, 233 * 3, 233 * 1, 233 * 1},
    {233 * 12, 233 * 4, 233 * 1, 233 * 1},
    {233 * 12, 233 * 5, 233 * 1, 233 * 1},
};

decor_t *deco_door(int val)
{
    decor_t *decor = NULL;
    sfSprite *sp = NULL;
    sfTexture *txt = NULL;

    if (val < 0 || val > 7)
        return (NULL);
    decor = decor_create(FALSE);
    txt = rget_texture("deco_tileset");
    sp = sfSprite_create();
    sfSprite_setTexture(sp, txt, sfTrue);
    sfSprite_setTextureRect(sp, DOOR_DICT[val]);
    decor_set_sprite(decor, sp);
    decor_set_height(decor, 233);
    return (decor);
}

decor_t *deco_desk(int val)
{
    decor_t *decor = NULL;
    sfSprite *sp = NULL;
    sfTexture *txt = NULL;

    if (val < 8 || val > 18)
        return (NULL);
    decor = decor_create(FALSE);
    txt = rget_texture("deco_tileset");
    sp = sfSprite_create();
    sfSprite_setTexture(sp, txt, sfTrue);
    sfSprite_setTextureRect(sp, DESK_DICT[val - 7]);
    decor_set_sprite(decor, sp);
    decor_set_height(decor, 233);
    return (decor);
}

decor_t *deco_box(int val)
{
    decor_t *decor = NULL;
    sfSprite *sp = NULL;
    sfTexture *txt = NULL;

    if (val < 19 || val > 24)
        return (NULL);
    decor = decor_create(TRUE);
    txt = rget_texture("deco_tileset");
    sp = sfSprite_create();
    sfSprite_setTexture(sp, txt, sfTrue);
    sfSprite_setTextureRect(sp, BOX_DICT[val - 18]);
    decor_set_sprite(decor, sp);
    decor_set_height(decor, 233);
    return (decor);
}

decor_t *deco_lamp(int val)
{
    decor_t *decor = NULL;
    sfSprite *sp = NULL;
    sfTexture *txt = NULL;

    if (val < 25 || val > 28)
        return (NULL);
    decor = decor_create(FALSE);
    txt = rget_texture("deco_tileset");
    sp = sfSprite_create();
    sfSprite_setTexture(sp, txt, sfTrue);
    sfSprite_setTextureRect(sp, LAMP_DICT[val - 26]);
    decor_set_sprite(decor, sp);
    decor_set_height(decor, 0);
    return (decor);
}

decor_t *deco_pic(int val)
{
    decor_t *decor = NULL;
    sfSprite *sp = NULL;
    sfTexture *txt = NULL;

    if (val < 29 || val > 31)
        return (NULL);
    decor = decor_create(FALSE);
    txt = rget_texture("deco_tileset");
    sp = sfSprite_create();
    sfSprite_setTexture(sp, txt, sfTrue);
    sfSprite_setTextureRect(sp, PIC_DICT[val - 30]);
    decor_set_sprite(decor, sp);
    decor_set_height(decor, 233);
    return (decor);
}
