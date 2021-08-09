/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "resource_holder.h"
#include "p_scheme.h"

const sfIntRect LOCKER_DICT[] = {
    {233 * 0, 233 * 2, 233 * 2, 233 * 2},
    {233 * 2, 233 * 0, 233 * 2, 233 * 2},
    {233 * 4, 233 * 0, 233 * 2, 233 * 2},
    {233 * 6, 233 * 0, 233 * 1, 233 * 2},
    {233 * 7, 233 * 0, 233 * 1, 233 * 2},
};

const sfIntRect WALL_DICT[] = {
    {233 * 5, 233 * 1, 233 * 1, 233 * 1},
    {233 * 1, 233 * 1, 233 * 1, 233 * 1},
};

decor_t *deco_subj(int val)
{
    decor_t *decor = NULL;
    sfSprite *sp = NULL;
    sfTexture *txt = NULL;
    animf_t *anim = NULL;

    if (val != 33)
        return (NULL);
    decor = decor_create(FALSE);
    anim = rget_animation("subject_animation");
    txt = rget_texture("subject");
    sp = sfSprite_create();
    sfSprite_setTexture(sp, txt, sfTrue);
    sfSprite_setTextureRect(sp, (sfIntRect) {0, 0, 233, 466});
    decor_set_sprite(decor, sp);
    decor_set_height(decor, 233);
    decor_set_animation(decor, anim);
    return (decor);
}

decor_t *deco_locker(int val)
{
    decor_t *decor = NULL;
    sfSprite *sp = NULL;
    sfTexture *txt = NULL;

    if (val < 34 || val > 39)
        return (NULL);
    decor = decor_create(FALSE);
    txt = rget_texture("deco_tileset");
    sp = sfSprite_create();
    sfSprite_setTexture(sp, txt, sfTrue);
    sfSprite_setTextureRect(sp, LOCKER_DICT[val - 33]);
    decor_set_sprite(decor, sp);
    decor_set_height(decor, 233);
    return (decor);
}

decor_t *deco_chair(int val)
{
    decor_t *decor = NULL;
    sfSprite *sp = NULL;
    sfTexture *txt = NULL;

    if (val != 40)
        return (NULL);
    decor = decor_create(FALSE);
    txt = rget_texture("deco_tileset");
    sp = sfSprite_create();
    sfSprite_setTexture(sp, txt, sfTrue);
    sfSprite_setTextureRect(sp, (sfIntRect) {233 * 11, 233 * 7, 233, 466});
    decor_set_sprite(decor, sp);
    decor_set_height(decor, 233);
    return (decor);
}

decor_t *deco_wall(int val)
{
    decor_t *decor = NULL;
    sfSprite *sp = NULL;
    sfTexture *txt = NULL;
    uint_t h = (val == 50 || val == 52) ? 233 : 0;
    float z = 50;
    sfIntRect rect = WALL_DICT[0];

    if (val < 50 || val > 53)
        return (NULL);
    rect = (val == 52 || val == 53) ? WALL_DICT[1] : rect;
    decor = decor_create(FALSE);
    txt = rget_texture("fw_tileset");
    sp = sfSprite_create();
    sfSprite_setTexture(sp, txt, sfTrue);
    sfSprite_setTextureRect(sp, rect);
    decor_set_sprite(decor, sp);
    decor_set_height(decor, h);
    decor_set_zoffset(decor, z);
    return (decor);
}
