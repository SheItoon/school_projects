/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** resource_holder.c
*/

#include "gcontext.h"
#include "resource_holder.h"

int rload_font(cchar_t filename, cchar_t name)
{
    gcontext_t *ctx = get_app_context();
    sfFont *font = sfFont_createFromFile(filename);

    map_insert(ctx->font_data, hash_str(name), font);
    return (0);
}

sfFont *rget_font(cchar_t name)
{
    gcontext_t *ctx = get_app_context();
    sfFont *font = 0;

    font = map_get(ctx->font_data, hash_str(name));
    return (font);
}
