/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <SFML/Graphics.h>
#include "standard_session.h"
#include "resource_loaders.h"
#include "istl/utility.h"
#include "init_functions.h"
#include "menu_sessions.h"
#include "read_map.h"
#include "scheme.h"

const map_elems_t MAP_DICT[] = {
    {' ', T_EMPTY},
    {'A', T_LABWALLBLOOD_1},
    {'Z', T_LABWALLBLOOD_2},
    {'E', T_LABWALLRIFT_1},
    {'R', T_LABWALLRIFT_2},
    {'T', T_LABWALL},
    {'Y', T_FLOOROFFICE_1},
    {'I', T_FLOOROFFICE_2},
    {'O', T_FLOOROFFICE_3},
    {'P', T_FLOOROFFICE_4},
    {'Q', T_FLOOROFFICEBLOOD_1},
    {'S', T_FLOOROFFICEBLOOD_2},
    {'D', T_OFFWALL_1},
    {'F', T_DARKLAB},
    {'G', T_IRONWALL},
    {'H', T_IRONWALLSCRATCH_1},
    {'J', T_IRONWALLSCRATCH_2},
    {'K', T_DARKLABWALL},
    {'L', T_DARKLABWALLBLOOD_1},
    {'M', T_DARKLABWALLBLOOD_2},
    {'W', T_PURPLEWALLOFFICE_1},
    {'X', T_PURPLEWALLOFFICE_2},
    {'C', T_GRAYWALLOFFICE_1},
    {'V', T_GRAYWALLOFFICE_2},
    {'B', T_LABFLOOR},
    {'N', T_LABFLOORRIFT},
    {',', T_LABFLOORBLOOD},
    {';', T_LABFLOORRIFTBLOOD},
    {':', T_CONCRETE},
    {0, -1}
};

const map_elems_t MAP_DICT2[] = {
    {'X', 1999},
    {'A', 3},
    {'B', 13},
    {'C', 14},
    {'D', 15},
    {'E', 50},
    {'F', 51},
    {'G', 52},
    {'H', 53},
    {'S', 33},
    {0, -1}
};

void make_global_text(cchar_t str, sfText *text)
{
    utype_t var = {0};

    if (str == 0 || text == 0)
        return;
    var.ptr = text;
    utility_set_var(str, var);
}

void init_texts(scene_t *scene)
{
    sfText *text = sfText_create();

    sfText_setFont(text, rget_font("bellota"));
    sfText_setColor(text, sfColor_fromRGB(170, 41, 66));
    sfText_setCharacterSize(text, 48);
    sfText_setPosition(text, (sfVector2f){20, 10});
    sfText_setString(text, "000");
    scene_linko(scene, RO_TEXT, text);
    make_global_text("health_txt", text);
    text = sfText_copy(text);
    sfText_setColor(text, sfColor_fromRGB(199, 135, 18));
    sfText_setPosition(text, (sfVector2f){130, 10});
    sfText_setString(text, "000");
    scene_linko(scene, RO_TEXT, text);
    make_global_text("money_txt", text);
}

void init_guidata(gcontext_t *ctx)
{
    sfRectangleShape *rshape = 0;
    sfRectangleShape *btn = sfRectangleShape_create();

    init_buttons(ctx->guiscene);
    rshape = gui_get_health_bar();
    scene_linko(ctx->guiscene, RO_RSHAPE, rshape);
    rshape = gui_get_money_bar();
    scene_linko(ctx->guiscene, RO_RSHAPE, rshape);
    init_texts(ctx->guiscene);
}

void init_gdata(gcontext_t *ctx)
{
    action_t action;
    creature_t *hero = creature_create(20, 466);
    sfSprite *sprite = NULL;

    app_init_window(sfVideoMode_getDesktopMode());
    register_standard_events();
    load_resources();
    load_level("resources/maps/main_level.txt",
            "resources/maps/main_deco.txt", ctx);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, rget_texture("main_hero"), FALSE);
    sfSprite_setTextureRect(sprite, (sfIntRect) {0, 0, 233, 466});
    creature_set_sprite(hero, sprite);
    sfSprite_destroy(sprite);
    scene_linko(ctx->appscene, RO_CREATURE, hero);
    utility_set_var("hero", (utype_t) {.ptr = hero});
}

void load_level(char const *filename, cchar_t decolvl, gcontext_t *ctx)
{
    int **lvl = read_map(filename, MAP_DICT);
    int **deco = read_map(decolvl, MAP_DICT2);
    scheme_t *s = scheme_create(lvl, 52, 21);
    scheme_t *d = scheme_create(deco, 52, 21);

    decor_toggle_dec(d);
    scheme_unpack(s, ctx->bgscene);
    scheme_unpack(d, ctx->appscene);
}
