/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "gcontext.h"
#include "resource_holder.h"

sfTexture *rget_texture(cchar_t res)
{
    gcontext_t *context = get_app_context();
    sfTexture *texture = 0;

    if (context->texture_data == 0)
        return (0);
    texture = (sfTexture*)map_get(context->texture_data, hash_str(res));
    return (texture);
}

animf_t *rget_animation(cchar_t name)
{
    gcontext_t *context = get_app_context();
    animf_t *anim = 0;

    if (name == 0)
        return (0);
    anim = (animf_t *)map_get(context->animation_data, hash_str(name));
    return (anim);
}

int rload_texture(cchar_t filename, cchar_t name, sfIntRect const *rect)
{
    gcontext_t *context = get_app_context();
    sfTexture *texture = 0;

    if (context->texture_data == 0 || filename == 0 || name == 0)
        return (-1);
    texture = sfTexture_createFromFile(filename, rect);
    sfTexture_setRepeated(texture, sfTrue);
    map_insert(context->texture_data, hash_str(name), texture);
    return (0);
}

int rload_animation(animf_t const *anim, cchar_t name)
{
    gcontext_t *ctx = get_app_context();

    if (anim == 0 || name == 0)
        return (-1);
    map_insert(ctx->animation_data, hash_str(name), anim);
    return (0);
}
