/*
** EPITECH PROJECT, 2019
** loading screen
** File description:
** l
*/

#include "my_hunter.h"

void rotate_bol(params_t *params)
{
    float interval = sfTime_asMilliseconds(sfMilliseconds(300));
    float time = sfTime_asMilliseconds(sfClock_getElapsedTime
                                       (params->globalclock));
    static float pastime = 0;
    float elapsed = time - pastime;

    if (elapsed > interval) {
        sfSprite_rotate(params->bol, randomizer(360));
        pastime = time;
    }
}

void check_top(params_t *params)
{
    if (params->bolrec.top >= 2304)
        params->bolrec.top = 0;
}

void animate_bol(params_t *params)
{
    float interval = sfTime_asMilliseconds(sfMilliseconds(30));
    float time = sfTime_asMilliseconds(sfClock_getElapsedTime
                                       (params->globalclock));
    static float pastime = 0;
    float elapsed = time - pastime;

    if (elapsed > interval) {
        params->bolrec.left += 256;
        if (params->bolrec.left >= 2048 && params->bolrec.top >= 2048) {
            params->bolrec.top = 0;
            params->bolrec.left = 0;
        }
        if (params->bolrec.left >= 2560) {
            params->bolrec.left = 0;
            params->bolrec.top += 256;
            check_top(params);
        }
        pastime = time;
    }
    sfSprite_setTextureRect(params->bol, params->bolrec);
}
void screensaving(params_t *params)
{
    while (sfRenderWindow_isOpen(params->window) && params->now == LOADING) {
        while (sfRenderWindow_pollEvent(params->window, &params->event)) {
            if (params->event.type == sfEvtClosed) {
                sfRenderWindow_close(params->window);
                params->now = ENDLOAD;
            }
        }
        sfRenderWindow_clear(params->window, sfBlack);
        sfRenderWindow_drawSprite(params->window, params->loading, NULL);
        animate_bol(params);
        rotate_bol(params);
        sfRenderWindow_drawSprite(params->window, params->bol, NULL);
        sfRenderWindow_display(params->window);
    }
}

void prepare_loading(params_t *params)
{
    create_mywindow(1920,1080,"test",params);
    params->winsize = sfRenderWindow_getSize(params->window);
    init_utils(params);
    window_set(params);
    params->loadingtex = sfTexture_createFromFile
        ("ressources/loadingscreen.png", NULL);
    params->loading = sfSprite_create();
    sfSprite_setTexture(params->loading, params->loadingtex, sfFalse);
    params->boltex = sfTexture_createFromFile("ressources/bol.png", NULL);
    params->bolrec = (sfIntRect){0,0,256,256};
    params->bol = sfSprite_create();
    sfSprite_setTexture(params->bol, params->boltex, sfFalse);
    sfSprite_setTextureRect(params->bol, params->bolrec);
    sfSprite_setPosition(params->bol, (sfVector2f){300, 200});
}
