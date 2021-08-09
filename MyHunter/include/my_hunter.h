/*
** EPITECH PROJECT, 2019
** my hunter lib
** File description:
** list of all functions and structures used in my_hunter
*/

#ifndef _HUNTER_
#define _HUNTER_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Network.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

typedef enum states
{
    LOADING,
    GAMING,
    START,
    ENDGAME,
    ENDLOAD,
} states_e;

typedef enum view_states
{
    SEMI,
    HARD,
    WHAT,
    HELL,
} view_e;

typedef struct weapon
{
    sfSprite *bow;
    sfTexture *bowtex;
    sfIntRect recbow;
} weapon_s;

typedef struct prism
{
    sfSprite *obeamos;
    sfTexture *obama;
    sfIntRect obeam;
} obaprism_s;

typedef struct params
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfClock *globalclock;
    sfEvent event;
    weapon_s weap;
    sfView *view2;
    sfVector2f position;
    sfVector2f scale;
    obaprism_s pris;
    sfSprite *obamagod;
    sfTexture *obeeanus;
    sfIntRect obarec;
    sfFont *score;
    sfText *scoretext;
    sfVector2u winsize;
    sfIntRect shrekrec;
    sfTexture *shrektex;
    sfSprite *shrek;
    sfTexture *tf2tex;
    sfSprite *tf2;
    sfBool flag;
    sfIntRect tf2rec;
    sfFont *nbfont;
    int value;
    char *valuestr;
    sfText *nbr;
    sfTexture *cursortex;
    sfSprite *cursor;
    float multi;
    sfHttp *http;
    sfHttpRequest *request;
    sfSound *chargebow;
    sfSoundBuffer *chargebuff;
    sfHttpResponse **response;
    sfMusic *music;
    sfSprite *skyrim;
    sfTexture *awake;
    sfIntRect finallyy;
    sfThread *thread_init;
    sfMutex *lock;
    sfSprite *loading;
    sfTexture *loadingtex;
    sfSprite *bol;
    sfTexture *boltex;
    sfIntRect bolrec;
    float level;
    states_e now;
    view_e lvl;
    sfText *goaltext;
    sfFont *goalf;
    float goal;
} params_t; 

char *get_score(int nbr);
int number_digits(int nbr);
int randomizer(int n);
void hit(params_t *params);
void create_mywindow(int width, int height, char *name, params_t *params);
void window_event(params_t *params);
void obama_care(params_t *params);
void bow_init(params_t *params);
void anim_bow(params_t *params);
void anim_prism2(params_t *params);
void anim_prism(params_t *params);
void goumed(params_t *params);
void params_init(params_t *params);
void obama_care2(params_t *params);
void window_set(params_t *params);
void draw_all(params_t *params);
void display_all(params_t *params);
void clear_n_set(params_t *params);
void hunter(params_t *params);
void hunter_init(void *not_params);
void the_game(params_t *params);
int norminator(void);
void hp_init(params_t *params, int check);
void init_web(params_t *params);
void init_sprite(params_t *params);
void init_rect(params_t *params);
void init_score(params_t *params);
void init_audio(params_t *params);
void init_text(params_t *params);
void init_last_text(params_t *params);
void init_skyrim_n_loading(params_t *params);
int my_getnbr(char const *str);
int randomizer(int n);
void case_one(params_t *params);
void case_second(params_t *params);
void shrek(params_t *params);
void skyriom(params_t *params);
void hp_init(params_t *params, int check);
void cursor_init(params_t *params);
void screensaving(params_t *params);
void init_utils(params_t *params);
void prepare_loading(params_t *params);
void init_goal(params_t *params);
#endif
