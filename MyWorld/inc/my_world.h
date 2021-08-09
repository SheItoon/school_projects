/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main file of the program
*/

#ifndef MY_WORLD
#define MY_WORLD

#include <math.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "enum.h"
#include "button.h"
#include "slider.h"
#include "struct.h"
#include "event.h"
#include "init_loading.h"
#include "loader.h"
#include "config.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <stdio.h>
#define MAP_X (6)
#define MAP_Y (6)

void analyse_event(data_game *data, sfEvent event);
void input(data_game *data);
void reset_map(data_game *data);
void free_map(data_game *data);
void increase_size(data_game *data);
void decrease_size(data_game *data);
void display_sprite(data_game *data);
void load_interface(data_game *data);
void add_button(data_game *data, sfVector2f position, sfTexture *texture, char *name);
void select_corner(data_game *data);
void select_tile(data_game *data);
void change_select_corner(data_game *data);
void change_select_tile(data_game *data);
void load_button(data_game *data);
void check_button(sfVector2i position, data_game *data);
void change_dir(data_game *data);
int draw_2d_map(data_game *data);
int compare(char const *str1, char const *str2);
sfVector2f **create_2d_map(int **tree_dim_map, data_game *data);
sfVector2f project_iso_point(int x, int y, int z);
sfTexture *get_texture(data_game *data, int x, int y);
int my_strlen(char *str);
void my_putstr(char *str);
void my_putshrek(void);
int parse_shrek(data_game *data, char key);
void display_help(void);
void set_menu(data_game *data);
void set_play(data_game *data);
void unload_game(data_game *data);
void shortcut(data_game *data);
void draw_selection(data_game *data);
void set_exit(data_game *data);
char *get_score(int nbr);
void save_map(data_game *data);
void set_load(data_game *data);
void set_hover_tex(data_game *data);
void display_how_to_play(data_game *data);
void how_to_play(data_game *data);
void create_button_how(data_game *data);
void handle_event(data_game *data, sfEvent event);
int my_getnbr(char const *str);
void my_world(data_game *data);
int get_row(char *file);
sfVector2f get_vector(int fd, data_game *data);
#endif //MY_WORLD
