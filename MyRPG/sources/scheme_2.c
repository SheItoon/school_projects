/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "resource_holder.h"
#include "decoration.h"
#include "p_scheme.h"
#include "istl/shared_ptr.h"

int scheme_unpack(scheme_t const *scheme, scene_t *scene)
{
    sfVector2f vec = (sfVector2f) {0, 0};
    uint_t c = 0;

    if (scheme == NULL || scene == NULL)
        return (-1);
    for (uint_t i = 0; i < scheme->height; i++) {
        for (uint_t j = 0; j < scheme->width; j++) {
            vec.x = scheme->tsize * j;
            vec.y = scheme->tsize * i;
            c += scheme_loadobj(scheme, scene, vec, scheme->tiles[i][j]);
        }
    }
    return (c);
}

int scheme_loadobj(
        scheme_t const *sc,
        scene_t *scene,
        sfVector2f pos,
        int value)
{
    decor_t *decor = NULL;
    sfSprite *sprite = NULL;

    if (scene == NULL || value < 0)
        return (0);
    sprite = sfSprite_create();
    decor = sc->translator(sc, value);
    decor_set_position(decor, pos);
    scene_linko(scene, RO_DECOR, decor);
    return (0);
}

void decor_toggle_dec(scheme_t *scheme)
{
    if (scheme == NULL)
        return;
    if (scheme->translator == scheme_translate)
        scheme->translator = scheme_translate2;
    else
        scheme->translator = scheme_translate;
}

decor_t *scheme_translate2(scheme_t const *sc, int val)
{
    decor_t *decor = NULL;

    if (sc == NULL)
        return (NULL);
    decor = (decor == NULL) ? deco_door(val) : decor;
    decor = (decor == NULL) ? deco_desk(val) : decor;
    decor = (decor == NULL) ? deco_box(val) : decor;
    decor = (decor == NULL) ? deco_pic(val) : decor;
    decor = (decor == NULL) ? deco_lamp(val) : decor;
    decor = (decor == NULL) ? deco_subj(val) : decor;
    decor = (decor == NULL) ? deco_wall(val) : decor;
    return (decor);
}
