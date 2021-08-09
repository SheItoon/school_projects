/*
** EPITECH PROJECT, 2020
** combat
** File description:
** combat
*/

#include "combat_session.h"
#include "normal.h"
#include "hacker.txt"
#include "standard_session.h"
#include "istl/utility.h"

const int mob[] = {0, 2};

int check_buttons(combat_t *entities, sfMouseButtonEvent mouse)
{
    size_t count = sizeof(entities->button.sprite) / 
    (sizeof(*entities->button.sprite));
    sfFloatRect rect;

    for (size_t i = 0; i < count; i++) {
        rect = sfSprite_getGlobalBounds(entities->button.sprite[i]);
        if (sfFloatRect_contains(&rect, mouse.x, mouse.y))
            return (i + 1);
    }
    return (0);
}

int check_events_fight(sfRenderWindow *window, combo_t *combo, 
combat_t *entities, int index)
{
    sfEvent event;
    int action = 0;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtTextEntered)
            normal_func(combo, event);
        if (event.type == sfEvtClosed) {
            return (sfRenderWindow_close(window), app_set_session(0), 1);
        }
        if (event.type == sfEvtMouseButtonReleased && 
        (action = check_buttons(entities, event.mouseButton))) {
            if ((action = fight(entities, index, action, window)) == 2)
                return (sfRenderWindow_close(window), app_set_session(0), 1);
            else if (action == 1)
                return (1);
        }
        sfClipboard_setString(secret[rand() % (sizeof(secret)
        / sizeof(*secret))]);
    }
    return (0);
}

void draw(sfRenderWindow *window, combat_t *entities, int index, 
sfClock *clock)
{
    static int e = 0;

    if (e == 0) {
        entities->state = (sfRenderStates) {sfBlendAlpha, 
        sfTransform_Identity, NULL,
        sfShader_createFromFile(NULL, NULL, "resources/shaders/wave")};
        e++;
    }
    sfShader_setFloatUniform((sfShader *)entities->state.shader, "time",
    sfTime_asSeconds(sfClock_getElapsedTime(clock)));
    sfRenderWindow_drawRectangleShape(window, 
    entities->background, &entities->state);
    sfRenderWindow_drawSprite(window, entities->mob.sprite[index], NULL);
    sfRenderWindow_drawSprite(window, 
    entities->player.sprite[entities->player.act], NULL);
    sfRenderWindow_drawRectangleShape(window, entities->menu, NULL);
    for (size_t i = 0; i < 3; i++)
        sfRenderWindow_drawSprite(window, entities->button.sprite[i], NULL);
    draw_hp(entities, index, window);
}

void init_gui(combat_t *entities, sfRenderWindow *window)
{
    static int init = 0;

    if (!init) {
        init_sound(&entities->oof, entities);
        init_mob(&entities->mob, window);
        init_player(&entities->player, window);
        init_button(&entities->button, window, entities);
        init_bar(entities, window);
        init = 1;
    }
    reset_hp_dmg(entities);
}

void combat_session(void)
{
    gcontext_t *context = get_app_context();
    int fight = 1;
    combo_t *combo = malloc(sizeof(combo_t));
    static combat_t *entities = NULL;
    utype_t *ptr = utility_get_var("enemy_ptr");
    int index = mob[rand() % 1];

    app_set_session(standart_session);
    if (context->window == 0)
        return;
    if (entities == NULL)
        entities = malloc(sizeof(combat_t));
    init_gui(entities, context->window);
    while (fight && sfRenderWindow_isOpen(context->window)) {
        sfRenderWindow_clear(context->window, sfBlue);
        if (check_events_fight(context->window, combo, entities, index))
            return;
        draw(context->window, entities, index, context->frame_clock);
        sfRenderWindow_display(context->window);
    }
    free(combo);
}
