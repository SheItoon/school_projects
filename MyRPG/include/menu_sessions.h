/*
** EPITECH PROJECT, 2020
** menu sessions
** File description:
** menu_session.h
*/

#ifndef MENU_SESSION_H
#define MENU_SESSION_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

/*!
    \brief the **state_t** enum defines the return value of the
    *main_menu_session()* functions and what action is expected from the rest
    of the program.
*/
typedef enum SELECTED_ITEM {
    OPTIONS, PLAY, QUIT, STATUS_NONE
} (state_t);

/*!
    \brief these static variables define the path of assets needed in the
    main menu.
*/
static cchar_t backgroundtx_path = "./resources/background.jpg";
static cchar_t menumusic_path = "./resources/musics/menu.ogg";

typedef struct ui_btn_s ui_button_t;
typedef struct ui_btn_s
{
    sfText *text;
    sfFont *font;
    sfRectangleShape *bckgrd;
    ui_button_t *next;
    ui_button_t *first;
} ui_button_t;

/*!
    \brief The **wrapper_menu_t** structure contains all things related to the
    main menu of the game. It should be free'd once the main menu is done being
    displayed.
*/
typedef struct gamemenu_s
{
    sfMusic *song;
    sfSprite *play;
    sfSprite *quit;
    sfTexture *play_t;
    sfTexture *quit_t;
} wrapper_menu_t;




// main_menu_session.c
/*!
    \brief The *main_menu_session()* function returns and int -- usually either
    2 or 3, defining wether the game should be loaded or not. See the
    **state_t** enum for more info.
    \author B. Guillemoles
*/
state_t menu_session(void);

/*!
    \brief Loads a text with a red rectangle shape background, to serve as a
    basic button.
    \author B. Guillemoles
*/
ui_button_t *load_menu_button(cchar_t, ui_button_t *, sfVector2f, sfVector2f);

// main_menu_handler.c
/*!
    \brief Session handler specific to the **wrapper_menu_t** structure. Handles
    basic events, such as a mouseButton_released event triggered, or an
    sfEvtClosed event.
    \author B. Guillemoles
*/
state_t main_menu_events(gcontext_t *ctx, wrapper_menu_t menu_info, sfEvent *);
/*!
    \brief Proper destructor for the **wrapper_menu_t** structure.
    \author B. Guillemoles
*/
void destroy_menu_struct(wrapper_menu_t menu_info);
/*!
    \brief Handles display for the **wrapper_menu_t** structure.
    \author B. Guillemoles
*/
void display_menu_struct(gcontext_t *ctx, wrapper_menu_t menu_info, sfEvent);

// main_menu_misc.c
/*!
    \brief displays a button.
    \author B.Guillemoles
*/
void drawbtn(sfRenderWindow *win, ui_button_t *btn, sfRenderStates *rdr);
/*!
    \brief updates button scale drawing if mouse position is above the button.
    \author B.Guillemoles
*/
ui_button_t *update_button_scale(sfEvent event, ui_button_t *btns);


// opt_menu.c
/*!
    \brief Loads specific **wrapper_menu_t** structure for the options menu,
    and handles display for this specific menu. Returns either *NONE* or *QUIT*.
    \author B. Guillemoles
*/
state_t options_menu(gcontext_t *ctx, wrapper_menu_t *menu_info);

#endif /* MENU_SESSION_H */
