/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#include <SFML/Graphics.h>
#include "standard_session.h"
#include "istl/utility.h"
#include "init_functions.h"

sfRectangleShape *gui_get_btn_bar(void)
{
    sfRectangleShape *bar = sfRectangleShape_create();

    sfRectangleShape_setSize(bar, (sfVector2f){242, 68});
    sfRectangleShape_setPosition(bar, (sfVector2f){230, 10});
    sfRectangleShape_setFillColor(bar, sfColor_fromRGBA(0, 0, 0, 160));
    sfRectangleShape_setOutlineThickness(bar, 2);
    return (bar);
}

sfRectangleShape *gui_get_health_bar(void)
{
    sfRectangleShape *bar = sfRectangleShape_create();

    sfRectangleShape_setSize(bar, (sfVector2f){100, 68});
    sfRectangleShape_setPosition(bar, (sfVector2f){10, 10});
    sfRectangleShape_setFillColor(bar, sfColor_fromRGBA(0, 0, 0, 160));
    sfRectangleShape_setOutlineThickness(bar, 2);
    return (bar);
}

sfRectangleShape *gui_get_money_bar(void)
{
    sfRectangleShape *bar = sfRectangleShape_create();

    sfRectangleShape_setSize(bar, (sfVector2f){100, 68});
    sfRectangleShape_setPosition(bar, (sfVector2f){120, 10});
    sfRectangleShape_setFillColor(bar, sfColor_fromRGBA(0, 0, 0, 160));
    sfRectangleShape_setOutlineThickness(bar, 2);
    return (bar);
}

void link_buttons(scene_t *scene)
{
    sfRectangleShape *btn = 0;
    sfVector2f pos = (sfVector2f){240, 20};
    cchar_t texts[] = {
        "tower_tesla",
        "tower_gatlin",
        "tower_snipe",
        "tower_frost"
    };

    for (int i = 0; i < 4; i++) {
        btn = sfRectangleShape_create();
        sfRectangleShape_setPosition(btn, pos);
        sfRectangleShape_setSize(btn, (sfVector2f){48, 48});
        sfRectangleShape_setTexture(btn, rget_texture(texts[i]), sfTrue);
        sfRectangleShape_setOutlineThickness(btn, 1);
        scene_linko(scene, RO_RSHAPE, btn);
        pos.x += 58;
    }
}

void init_buttons(scene_t *scene)
{
    sfRectangleShape *rshape = 0;

    rshape = gui_get_btn_bar();
    scene_linko(scene, RO_RSHAPE, rshape);
    link_buttons(scene);
}
