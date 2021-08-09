/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "csfml_toolbox.h"
#include "private/p_decoration.h"

void decor_set_sprite(decor_t *decor_p, sfSprite const *sprite)
{
    sfFloatRect bds = (sfFloatRect) {0, 0, 0, 0};

    if (decor_p == NULL)
        return;
    bds = (sprite == NULL) ? bds : sfSprite_getGlobalBounds(sprite);
    decor_p->sprite = (sprite == NULL) ? NULL : sfSprite_copy(sprite);
    decor_p->height = bds.height;
}

void decor_set_height(decor_t *decor_p, uint_t h)
{
    if (decor_p == NULL)
        return;
    decor_p->height = h;
}

void decor_draw(
        sfRenderWindow * window,
        void const *decor_p,
        sfRenderStates const *states)
{
    decor_t const *decor = decor_p;

    if (window == NULL || decor_p == NULL)
        return;
    sfRenderWindow_drawSprite(window, decor->sprite, states);
}

sfFloatRect decor_getgbounds(void const *decor_p)
{
    decor_t const *decor = decor_p;
    sfFloatRect bds = (sfFloatRect) {0, 0, 0, 0};

    if (decor == NULL || decor->sprite == NULL)
        return (bds);
    bds = sfSprite_getGlobalBounds(decor->sprite);
    bds.top += (bds.height - decor->height + 233);
    bds.height = decor->height + decor->z_offset;
    return (bds);
}

void decor_update(void *decor_p, sfTime delta, scene_t *scene)
{
    decor_t *decor = decor_p;
    sfIntRect *frame = NULL;

    if (decor == NULL)
        return;
    T_ADD(decor->in_state, delta);
    if (decor->anim == NULL || decor->sprite == NULL)
        return;
    frame = animf_get_frame(decor->anim, decor->in_state);
    if (frame != NULL)
        sfSprite_setTextureRect(decor->sprite, *frame);
}
