/*
** EPITECH PROJECT, 2019
** rand function
** File description:
** rand
*/

#include "my_hunter.h"

int randomizer(int n)
{
    int ye;

    ye = rand() % n;
    return(ye);
}

void init_goal(params_t *params)
{
    params->goalf = sfFont_createFromFile("ressources/open-sans.light.ttf");
    params->goaltext = sfText_create();
    sfText_setString(params->goaltext, get_score(params->goal));
    sfText_setPosition(params->goaltext, (sfVector2f){0, params->winsize.y /2});
    sfText_setCharacterSize(params->goaltext, 49);
    sfText_setFont(params->goaltext, params->goalf);
    sfText_scale(params->goaltext, (sfVector2f){2, 3});
}
