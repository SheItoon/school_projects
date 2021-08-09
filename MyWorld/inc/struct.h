/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main file of the program
*/

#ifndef STRUCT
#define STRUCT

typedef struct camera_s
{
    sfView *camera;
    sfView const *default_view;
    float factor;
} camera_t;

typedef struct thread_s
{
    sfMutex *lock;
    sfThread *init;
} thread_t;

typedef enum state_e
{
    GAME,
    OVER,
    LOADING,
    MENU,
    HELP,
    PAUSE,
    ENDGAME,
    ENDLOAD,
    START,
} state_e;

typedef struct system
{
    sfClock *clock;
    sfShader *shader;
    sfRenderStates render;
} sys_t;

typedef struct percent
{
    sfVertex *vertices;
} percent_t;

typedef struct loader
{
    sfSprite *loading;
    sfSprite *textloading;
    sfSprite *scared;
    sfSprite *background;
    sfSprite *ground;
    sfTexture *loadtex;
    sfTexture *textloadtex;
    sfTexture *scaredtex;
    sfTexture *background_tex;
    sfTexture *ground_tex;
    sfIntRect loadrect;
    sfIntRect textrect;
    sfIntRect scaredrec;
    sfFont *font;
    sfText *text;
    sfBool ready;
    int loaded;
    int toload;
    percent_t percent;
} loader_t;

typedef struct sprite_s
{
    sfSprite *font;
    sfSprite *help;
} sprite_t;

typedef struct texture_s
{
    sfTexture *font;
    sfTexture *snow;
    sfTexture *stone;
    sfTexture *dirt;
    sfTexture *grass;
    sfTexture *button;
    sfTexture *button_hover;
    sfTexture *button_press;
    sfTexture *button_l;
    sfTexture *button_hover_l;
    sfTexture *button_press_l;
    sfTexture *slider;
    sfTexture *help_box;
    sfTexture *help;
} texture_t;

typedef struct icon_s
{
    sfImage *image;
    sfUint8 *pixel;
} icon_t;

typedef struct combo_s
{
    int done;
    sfText *text;
    char *buffer;
} combo_t;

typedef struct save_s
{
    int has_loaded;
} save_t;

typedef struct data_game_s
{
    sfRenderWindow *window;
    camera_t cam;
    thread_t thread;
    sfView *interface_view;
    sfVector2u window_size;
    sfVector2f winsize_f;
    state_e state;
    sys_t sys;
    loader_t loader;
    int map_x;
    int map_y;
    sfVector2f **map;
    sfVector2f **selected_tile;
    sfFont *font;
    texture_t *textures;
    button_t *button;
    slider_t *slider;
    sprite_t *sprites;
    select_t selection;
    direction_t direction;
    icon_t icon;
    combo_t combo;
    save_t save;
} data_game;

#endif //STRUCT
