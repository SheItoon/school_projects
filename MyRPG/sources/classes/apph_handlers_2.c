/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** apph_handlers.c
*/

#include "gcontext.h"

int app_register(sfEventType type, callback_t func)
{
    gcontext_t *ctx = get_app_context();
    hash_value_t hash = 0;
    action_t action = (action_t){
        .custom = FALSE,
        .function = func
    };

    if (ctx->sfml_hdata == 0 || func == NULL)
        return (-1);
    hash = hash_data(&type, sizeof(sfEventType));
    map_insert(ctx->sfml_hdata, hash, &action);
    return (0);
}

int app_registerc(mdevent_type_t type, callback_t func)
{
    gcontext_t *ctx = get_app_context();
    hash_value_t hash = 0;
    action_t action = (action_t){
        .custom = TRUE,
        .function = func
    };

    if (ctx->cstm_hdata == 0 || func == NULL)
        return (-1);
    hash = hash_data(&type, sizeof(mdevent_type_t));
    map_insert(ctx->cstm_hdata, hash, &action);
    return (0);
}

action_t *app_get_handler(sfEventType type)
{
    gcontext_t *ctx = get_app_context();
    hash_value_t hash = hash_data(&type, sizeof(sfEventType));

    if (ctx->sfml_hdata == 0)
        return (0);
    return (map_get(ctx->sfml_hdata, hash));
}

action_t *app_get_chandler(mdevent_type_t type)
{
    gcontext_t *ctx = get_app_context();
    hash_value_t hash = hash_data(&type, sizeof(mdevent_type_t));

    if (ctx->cstm_hdata == 0)
        return (0);
    return (map_get(ctx->cstm_hdata, hash));
}

list_t *app_get_handlers(sfEventType type)
{
    gcontext_t *ctx = get_app_context();
    hash_value_t hash = hash_data(&type, sizeof(sfEventType));

    if (ctx->sfml_hdata == 0)
        return (0);
    return (map_get_all(ctx->sfml_hdata, hash));
}
