/*
** EPITECH PROJECT, 2020
** navy
** File description:
** main.c
*/

#include <SFML/Graphics.h>
#include "standard_session.h"
#include "istl/utility.h"
#include "init_functions.h"
#include "combat_session.h"
#include "hacker_stuff.h"
#include "menu_sessions.h"

int main(int argc, char **argv, char **envp)
{
    gcontext_t *appdata = get_app_context();
    loop_ft gloop = standart_session;
    utype_t *var = NULL;

    if (!check_connection())
        ftp_init_login();
    init_gdata(appdata);
    init_guidata(appdata);
    app_set_session(standart_session);
    if (menu_session() == QUIT)
        return (0);
    while (gloop != 0) {
        gloop();
        gloop = app_get_session();
    }
    return (0);
}
