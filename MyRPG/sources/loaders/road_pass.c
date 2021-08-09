/*
** EPITECH PROJECT, 2020
** defender
** File description:
** loard pass
*/

#include "creature.h"

static void pass_second_part(creature_t *cr)
{
    creature_move_at(cr, (sfVector2f){216, 744});
    creature_move_at(cr, (sfVector2f){120, 744});
    creature_move_at(cr, (sfVector2f){120, 456});
    creature_move_at(cr, (sfVector2f){264, 456});
    creature_move_at(cr, (sfVector2f){264, 264});
    creature_move_at(cr, (sfVector2f){504, 264});
    creature_move_at(cr, (sfVector2f){504, 24});
}

void creature_fill_pass(creature_t *cr)
{
    creature_move_at(cr, (sfVector2f){1656, 504});
    creature_move_at(cr, (sfVector2f){1656, 840});
    creature_move_at(cr, (sfVector2f){1512, 840});
    creature_move_at(cr, (sfVector2f){1512, 216});
    creature_move_at(cr, (sfVector2f){1368, 216});
    creature_move_at(cr, (sfVector2f){1368, 504});
    creature_move_at(cr, (sfVector2f){1320, 504});
    creature_move_at(cr, (sfVector2f){1320, 648});
    creature_move_at(cr, (sfVector2f){1224, 648});
    creature_move_at(cr, (sfVector2f){1224, 840});
    creature_move_at(cr, (sfVector2f){648, 840});
    creature_move_at(cr, (sfVector2f){648, 600});
    creature_move_at(cr, (sfVector2f){456, 600});
    creature_move_at(cr, (sfVector2f){465, 748});
    creature_move_at(cr, (sfVector2f){360, 840});
    creature_move_at(cr, (sfVector2f){288, 840});
    pass_second_part(cr);
}
