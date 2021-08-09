/*
** EPITECH PROJECT, 2020
** init
** File description:
** init_bar
*/

#include "combat_session.h"
const int life = 920;
const int life_m[] = {300, 0, 899};

void set_color(combat_t *entities, int i)
{
    entities->player.vertices[i].color = sfGreen;
    entities->mob.vertices[i].color = sfGreen;
}

void set_right_corner(combat_t *entities, int i, sfVector2f pos, 
sfVector2f mob)
{
    entities->player.vertices[i].position =
    (sfVector2f){pos.x + 
    sfSprite_getGlobalBounds(entities->player.sprite[0]).width,
    pos.y};
    entities->mob.vertices[i].position =
    (sfVector2f){mob.x + 
    sfSprite_getGlobalBounds(entities->mob.sprite[0]).width,
    mob.y};
}

void init_bar(combat_t *entities, sfRenderWindow *window)
{
    sfVector2f pos = sfSprite_getPosition(entities->player.sprite[0]);
    sfVector2f mob = sfSprite_getPosition(entities->mob.sprite[0]);

    for (int i = 0; i < 4; i++) {
        set_color(entities,i);
        if (i > 1) {
            set_right_corner(entities, i, pos, mob);
        } 
        if (i == 0) {
            entities->player.vertices[i].position =
            (sfVector2f){pos.x, pos.y};
            entities->mob.vertices[i].position =
            (sfVector2f){mob.x, mob.y};
        } else {
            entities->player.vertices[i].position =
            (sfVector2f){pos.x, pos.y + 40};
            entities->mob.vertices[i].position =
            (sfVector2f){mob.x, mob.y + 40};
        }
    }
}

void draw_hp(combat_t *e, int index, sfRenderWindow *window)
{
    float curr_p = (float) e->player.life / (float) (life * e->player.level);
    float actual_m = (float) e->mob.hp[index] / 
    (float) (life_m[index] * (1.33 * e->player.level));
    sfVector2f p = sfSprite_getPosition(e->player.sprite[0]);
    sfVector2f m = sfSprite_getPosition(e->mob.sprite[0]);
    float off_p = sfSprite_getGlobalBounds(e->player.sprite[0]).width;
    float off_m = sfSprite_getGlobalBounds(e->mob.sprite[0]).width;

    for (int i = 1; i < 3; i++) {
        e->player.vertices[i].position = (sfVector2f) 
        {(p.x + off_p) * curr_p, p.y + 40};
        e->mob.vertices[i].position = (sfVector2f) 
        {(m.x + off_m) * actual_m, m.y + 40};
        if (i == 1) {
            SET_POS;
        }
        sfRenderWindow_drawPrimitives(window, e->player.vertices, 4, 
        sfQuads, NULL);
        sfRenderWindow_drawPrimitives(window, e->mob.vertices, 4, 
        sfQuads, NULL);
    }
}