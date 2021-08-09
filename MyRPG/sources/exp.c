/*
** EPITECH PROJECT, 2020
** xp
** File description:
** exp
*/

#include "combat_session.h"

const int p_xp = 12;
const int drop_xp[] = {23, 0, 49};

void gain_exp(player_t *player, int index)
{
    if (player->xp_curr < player->xp_need)
        player->xp_curr += drop_xp[index];
    if (player->xp_curr >= player->xp_need) {
        player->xp_curr -= player->xp_need;
        player->level++;
        player->xp_need = p_xp * (player->level * 1.22);
    }
}