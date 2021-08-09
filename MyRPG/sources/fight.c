/*
** EPITECH PROJECT, 2020
** fight
** File description:
** bagar
*/

#include "combat_session.h"
#include <stdlib.h>

int bone_attack(combat_t *entities, int index, sfRenderWindow *window)
{
    entities->mob.hp[index] -= entities->player.damage;
    sfRenderWindow_drawSprite(window, entities->player.sprite[1], NULL);
    sfRenderWindow_drawSprite(window, entities->mob.sprite[index], NULL);
    draw_hp(entities, index, window);
    sfRenderWindow_display(window);
    sfSound_play(entities->mob.oof), sfSound_play(entities->player.oof);
    sfRenderWindow_clear(window, sfBlue), sfSleep(sfMilliseconds(400));
    sfRenderWindow_drawSprite(window, entities->player.sprite[0], NULL);
    sfRenderWindow_drawSprite(window, entities->mob.sprite[index + 1], NULL);
    if (index != 0)
        entities->player.life -= entities->mob.dmg[index - 1] / 1.5;
    else
        entities->player.life -= entities->mob.dmg[index] / 1.5;
    draw_hp(entities, index, window);
    sfRenderWindow_display(window), sfRenderWindow_clear(window, sfBlue);
    sfSleep(sfMilliseconds(400));
    if (entities->player.life <= 0)
        return (2);
    if (entities->mob.hp[index] <= 0) 
        return (gain_exp(&entities->player, index), 1);
    return (0);
}

int gun_attack(combat_t *entities, int index, sfRenderWindow *window)
{
    DRAW_START;
    entities->mob.hp[index] -= entities->player.damage;
    draw_hp(entities, index, window);
    sfRenderWindow_display(window), sfRenderWindow_clear(window, sfBlue);
    sfSleep(sfMilliseconds(400));
    sfRenderWindow_drawSprite(window, entities->player.sprite[2], NULL);
    sfRenderWindow_drawSprite(window, entities->mob.sprite[index + 1], NULL);
    sfSound_play(entities->player.oof), sfSound_play(entities->mob.oof);
    if (index != 0)
        entities->player.life -= entities->mob.dmg[index - 1] / 1.5;
    else
        entities->player.life -= entities->mob.dmg[index] / 1.5;
    draw_hp(entities, index, window);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlue), sfSleep(sfMilliseconds(400));
    if (entities->player.life <= 0)
        return (2);
    if (entities->mob.hp[index] <= 0)
        return (gain_exp(&entities->player, index), 1);
    return (0);
}

void run(void)
{
    return;
}

int fight(combat_t *entities, int index, int action, sfRenderWindow *window)
{
    int result = 0;

    switch (action) {
    case 1: result = bone_attack(entities, index, window);
        if (result == 1)
            return (1);
        else if (result == 2)
            return (2);
        break;
    case 2: result = gun_attack(entities, index, window);
        if (result == 1)
            return (1);
        else if (result == 2)
            return (2);
        break;
    case 3: return (run(), 2);
    default: return (0);
    }
    return (0);
}