/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "standard_session.h"
#include "gcontext.h"
#include <stdio.h>

int modh_btn_clicked(void *evt_p, gcontext_t *ctx)
{
    sfEvent evt;
    sfFloatRect rect = (sfFloatRect) {
        .top = 20,
        .left = 400,
        .width = 250,
        .height = 250
    };
    sfVector2i m;

    if (evt_p == NULL || ctx == NULL)
        return (-1);
    evt = *(sfEvent *)evt_p;
    m = (sfVector2i){evt.mouseButton.x, evt.mouseButton.y};
    return (0);
}
