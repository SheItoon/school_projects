/*
** EPITECH PROJECT, 2020
** init
** File description:
** combat_init
*/

#include "combat_session.h"
#include "texture.txt"

void reset_hp_dmg(combat_t *entities)
{
    for (int i = 0; i < 2; i++) {
        entities->mob.hp[i] = mob_hp[i] * (1.33 * entities->player.level);
        entities->mob.dmg[i] = mob_damage[i] * (1.29 * entities->player.level);
    }
    entities->player.life = p_life * entities->player.level;
    entities->player.damage = p_damage * entities->player.level;
}

void init_button(button_t *button, sfRenderWindow *window, 
combat_t *entities)
{
    size_t count = sizeof(button->texture) / sizeof(*(button->texture));
    sfVector2u pos = sfRenderWindow_getSize(window);

    for (size_t i = 0; i < count; i++) {
        button->texture[i] = sfTexture_createFromFile(texture_button[i], 
        NULL);
        button->sprite[i] = sfSprite_create();
        sfSprite_setTexture(button->sprite[i], button->texture[i], sfFalse);
        button->rect[i] = (sfVector2f) {pos.x * ((float) (i + .5) * .33)
        , pos.y * .66};
        sfSprite_setScale(button->sprite[i], (sfVector2f) {3, 3});
        sfSprite_setPosition(button->sprite[i], button->rect[i]);
    }
    SET_MENU;
    SET_BACKGROUND;
}

void init_mob(mob_t *mob, sfRenderWindow *window)
{
    size_t count = sizeof(mob->texture) / sizeof(*(mob->texture));
    sfVector2u pos = sfRenderWindow_getSize(window);

    for (size_t i = 0; i < count; i++) {
        mob->texture[i] = sfTexture_createFromFile(texture_mob,
        &rect_mob[i]);
        mob->sprite[i] = sfSprite_create();
        sfSprite_setTexture(mob->sprite[i], mob->texture[i], sfFalse);
        mob->rect[i] = (sfVector2f) {pos.x - rect_mob[i].width, 0};
        sfSprite_setPosition(mob->sprite[i], mob->rect[i]);
    }
    count = sizeof(mob->hp) / sizeof(*(mob->hp));
    for (size_t i = 0; i < count; i++) {
        mob->hp[i] = mob_hp[i];
        mob->dmg[i] = mob_damage[i];
    }
}

void init_player(player_t *player, sfRenderWindow *window)
{
    size_t count = sizeof(player->texture) / sizeof(*(player->texture));
    sfVector2u pos = sfRenderWindow_getSize(window);
    sfVector2f sprite_pos;

    for (size_t i = 0; i < count; i++) {
        player->texture[i] = sfTexture_createFromFile(texture_pl[i],
        NULL);
        player->sprite[i] = sfSprite_create();
        sfSprite_setTexture(player->sprite[i], player->texture[i], sfFalse);
        player->rect[i] = (sfVector2f) {100, 0};
        sfSprite_setPosition(player->sprite[i], player->rect[i]);
    }
    player->act = 0;
    player->life = p_life;
    player->damage = p_damage;
    player->level = p_level;
    player->xp_curr = 0;
    player->xp_need = p_xp_need;
    sprite_pos = sfSprite_getPosition(player->sprite[0]);
}

void init_sound(oof_t *oof, combat_t *entities)
{
    oof->damage_buffer = sfSoundBuffer_createFromFile
    ("resources/musics/classic_hurt.ogg");
    entities->mob.damage = sfSoundBuffer_createFromFile
    ("resources/musics/roblox_death.ogg");
    oof->damage = sfSound_create();
    sfSound_setBuffer(oof->damage, oof->damage_buffer);
    entities->mob.oof = sfSound_create();
    sfSound_setBuffer(entities->mob.oof, entities->mob.damage);
    entities->player.oof = sfSound_create();
    sfSound_setBuffer(entities->player.oof, oof->damage_buffer);
}