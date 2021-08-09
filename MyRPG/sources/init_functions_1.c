/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#include <SFML/Graphics.h>
#include "standard_session.h"
#include "istl/utility.h"
#include "init_functions.h"

void show_app_statistics(void)
{
    utype_t *var = 0;
}

loop_ft get_game_mode(gmode_t mode)
{
    loop_ft func = 0;

    func = (mode == STANDART) ? standart_session : func;
    return (func);
}

bool_t session_ended(void)
{
    gcontext_t *context = get_app_context();

    if (context->window != 0)
        return (!sfRenderWindow_isOpen(context->window));
    return (TRUE);
}

int register_standard_events(void)
{
    app_register(sfEvtMouseMoved, modh_mouse_moved);
    app_register(sfEvtMouseButtonPressed, modh_mouse_button);
    app_register(sfEvtMouseButtonReleased, modh_mouse_button);
    app_register(sfEvtKeyPressed, modh_key_pressed);
    return (0);
}
