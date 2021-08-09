/*
** EPITECH PROJECT, 2020
** load
** File description:
** load
*/

#include "my_world.h"

void swap_mobload(data_game *data, int check)
{
    static int mob = 0;

    if (check == 0) {
        data->loader.loadrect.top += 48;
        if (data->loader.loadrect.top >= 400)
            data->loader.loadrect.top = 271;
        sfSprite_setTextureRect(data->loader.loading,
        data->loader.loadrect);
    } else if (check == 1) {
        if (mob < 1 || mob > 1)
            data->loader.scaredrec.top -= 32;
        else
            data->loader.scaredrec.top -= 63;
        if (data->loader.scaredrec.top <= 169) {
            data->loader.scaredrec.top = 329;
            mob = -1;
        }
        sfSprite_setTextureRect(data->loader.scared,
        data->loader.scaredrec);
        mob++;
    }
}
