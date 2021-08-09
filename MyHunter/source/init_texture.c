/*
** EPITECH PROJECT, 2019
** init texture
** File description:
** init
*/

#include "my_hunter.h"

void init_text(params_t *params)
{
    if ((params->pris.obama = sfTexture_createFromMemory
         (&*sfHttpResponse_getBody(params->response[0])
          , my_getnbr(sfHttpResponse_getField(params->response[0]
                                              , "Content-Length"))
          , NULL)) == NULL)
        params->pris.obama = sfTexture_createFromFile
            ("ressources/offline_texture.jpg", NULL);
    if ((params->obeeanus = sfTexture_createFromMemory
         (&*sfHttpResponse_getBody(params->response[4])
          , my_getnbr(sfHttpResponse_getField(params->response[4]
                                              , "Content-Length"))
          , NULL)) == NULL)
        params->obeeanus = sfTexture_copy(params->pris.obama);
    if ((params->weap.bowtex = sfTexture_createFromMemory
         (&*sfHttpResponse_getBody(params->response[1])
          , my_getnbr(sfHttpResponse_getField(params->response[1]
                                              , "Content-Length"))
          , NULL)) == NULL)
        params->weap.bowtex = sfTexture_copy(params->pris.obama);
}

void init_last_text(params_t *params)
{
    if ((params->shrektex = sfTexture_createFromMemory
         (&*sfHttpResponse_getBody(params->response[5])
          , my_getnbr(sfHttpResponse_getField(params->response[5]
                                              , "Content-Length"))
          , NULL)) == NULL)
        params->shrektex = sfTexture_copy(params->pris.obama);
    if ((params->tf2tex = sfTexture_createFromMemory
         (&*sfHttpResponse_getBody(params->response[3])
          , my_getnbr(sfHttpResponse_getField(params->response[3]
                                              , "Content-Length"))
          , NULL)) == NULL)
        params->tf2tex = sfTexture_copy(params->pris.obama);
    if ((params->cursortex = sfTexture_createFromMemory
         (&*sfHttpResponse_getBody(params->response[2])
          , my_getnbr(sfHttpResponse_getField(params->response[2]
                                              , "Content-Length"))
          , NULL)) == NULL)
        params->cursortex = sfTexture_createFromFile
            ("ressources/cursor_offline.png", NULL);
}

void init_skyrim_n_loading(params_t *params)
{
    if ((params->awake = sfTexture_createFromMemory
         (&*sfHttpResponse_getBody(params->response[6])
          , my_getnbr(sfHttpResponse_getField(params->response[6]
                                              , "Content-Length"))
          , NULL)) == NULL)
        params->awake = sfTexture_copy(params->pris.obama);
}
