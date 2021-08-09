/*
** EPITECH PROJECT, 2019
** init structures
** File description:
** init
*/

#include "my_hunter.h"

void init_web(params_t *params)
{
    char *object[7] = {"/ressources/obamaprism.png","/ressources/bow_curso\
r_spritesheet.png", "/ressources/cursor.png", "/ressources/hp_tf2.png",
                       "/ressources/obamacare.png", "/shrek.png",
    "/ressources/yourefinallyawake.png"};

    params->response = malloc(sizeof(sfHttpResponse *) * 7);
    params->http = sfHttp_create();
    params->request = sfHttpRequest_create();
    sfHttp_setHost(params->http, "sherk.communis.me/",80);
    sfHttpRequest_setMethod(params->request, sfHttpGet);
    for (int i = 0; i < 7; i++) {
        sfHttpRequest_setUri(params->request, object[i]);
        params->response[i] = sfHttp_sendRequest(params->http, params->request,
                                                 sfSeconds(6));
    }
}

void init_sprite(params_t *params)
{
    params->obamagod = sfSprite_create();
    params->pris.obeamos = sfSprite_create();
    params->weap.bow = sfSprite_create();
    params->shrek = sfSprite_create();
    params->tf2 = sfSprite_create();
    params->cursor = sfSprite_create();
    params->skyrim = sfSprite_create();
    sfSprite_setPosition(params->tf2, (sfVector2f){params->winsize.x - 150, 0});
}

void init_rect(params_t *params)
{
    params->pris.obeam = (sfIntRect){0,0,128,128};
    params->obarec = (sfIntRect){0,0,128,128};
    params->weap.recbow = (sfIntRect){0,0,415,1080};
    params->shrekrec = (sfIntRect){0,0,60,60};
    params->tf2rec = (sfIntRect){0,0,150,150};
    params->finallyy = (sfIntRect){0,0,640,360};
}

void init_score(params_t *params)
{
    params->score = sfFont_createFromFile("ressources/open-sans.light.ttf");
    params->scoretext = sfText_create();
    sfText_setString(params->scoretext, "Score :");
    sfText_setPosition(params->scoretext, (sfVector2f){params->winsize.x/2,0});
    sfText_setCharacterSize(params->scoretext, 49);
    sfText_setFont(params->scoretext, params->score);
    sfText_scale(params->scoretext, (sfVector2f){2,3});
    params->nbfont = sfFont_createFromFile("ressources/PAPYRUS.TTF");
    params->nbr = sfText_create();
    sfText_setString(params->nbr, "0");
    sfText_setPosition(params->nbr, (sfVector2f){params->winsize.x/1.5,0});
    sfText_setCharacterSize(params->nbr, 49);
    sfText_setFont(params->nbr, params->nbfont);
    sfText_scale(params->nbr, (sfVector2f){2,3});
}

void init_audio(params_t *params)
{
    params->chargebuff = sfSoundBuffer_createFromFile
        ("ressources/opticor_charge.ogg");
    params->chargebow = sfSound_create();
    sfSound_setBuffer(params->chargebow, params->chargebuff);
    params->music = sfMusic_createFromFile("ressources/Ba_Bo_Bay.ogg");
}
