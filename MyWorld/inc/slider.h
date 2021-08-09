/*
** EPITECH PROJECT, 2019
** slider.h
** File description:
** create good slider
*/

#ifndef MUL_MY_WORLD_2019_SLIDER
#define MUL_MY_WORLD_2019_SLIDER

typedef struct slider_s
{
    char *name;
    int pos_cursor;
    int pos_x_min;
    int pos_x_max;
    int current_pos;
    int scale;
    sfSprite *slider;
    sfSprite *cursor;
    sfVector2f position;
    sfFloatRect cursor_rect;
    float value;
    struct slider_s *next;
} slider_t;

void add_slider(data_game *data, char *name, sfVector2f position);
void slider_set_slider_texture(data_game *data, char *name, sfTexture *texture, float scale);
void slider_set_cursor_texture(data_game *data, char *name, sfTexture *texture, float scale);
void slider_set_extreme_value(data_game *data, char *name, int min, int max);
void slider_set_cursor_position(data_game *data, char *name, int x_position);
void slider_press_cursor(data_game *data, sfVector2i mouse_pos);
void draw_slider(data_game *data);
void slider_destroy(data_game *data);
slider_t *get_slider(data_game *data, char *name);

#endif //MUL_MY_WORLD_2019_SLIDER
