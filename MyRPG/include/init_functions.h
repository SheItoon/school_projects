/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef INIT_FUNCTIONS_H_INCLUDED
#define INIT_FUNCTIONS_H_INCLUDED

typedef void (*loop_ft)(void);
typedef enum GAME_MODE {MENU, STANDART, PAUSE} gmode_t;

void init_gdata(gcontext_t *);
void init_guidata(gcontext_t *ctx);
loop_ft get_game_mode(gmode_t);
bool_t session_ended(void);
void show_app_statistics(void);
bool_t session_ended(void);
loop_ft get_game_mode(gmode_t mode);
int register_standard_events(void);
sfRectangleShape *gui_get_btn_bar(void);
sfRectangleShape *gui_get_health_bar(void);
sfRectangleShape *gui_get_money_bar(void);
void link_buttons(scene_t *scene);
void init_buttons(scene_t *scene);
void make_global_text(cchar_t str, sfText *text);
void init_texts(scene_t *scene);
void init_guidata(gcontext_t *ctx);
void init_gdata(gcontext_t *ctx);

void load_level(char const *filename, char const *deco, gcontext_t *ctx);

#endif
