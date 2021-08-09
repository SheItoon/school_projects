/*
** EPITECH PROJECT, 2019
** button.h
** File description:
** struct for the button
*/

#ifndef MUL_MY_RUNNER_2019_BUTTON_H
#define MUL_MY_RUNNER_2019_BUTTON_H

typedef struct data_game_s (data_game);

typedef struct button_s
{
    char *name;
    sfText *title;
    sfText *help_text;
    sfIntRect rect;
    sfSprite *idle;
    sfTexture *stand;
    sfTexture *hover;
    sfTexture *press;
    sfSprite *help_sprite;
    sfVector2f position;
    sfVector2f text_pos;
    button_tag_t tag;
    float time;
    float help_time;
    int help;
    int clicked;
    int pressed;
    void (*action)(data_game*);
    struct button_s *next;
} button_t;

void button_set_other_tex(data_game *data, char *name, sfTexture *hover, sfTexture *press);
void button_set_texture(data_game *data, sfTexture *texture, char *name);;
void button_set_text_pos(data_game *data, char *name, sfVector2f pos, int save);
void draw_button(data_game *data, button_tag_t displayed_tag);
void button_add_text_box(data_game *data, char *name, sfTexture *texture, sfVector2f scale);
void button_add_text_box_message(data_game *data, char *name, char *text);
void display_help_box(data_game *data, button_t *button);
void button_help_display(data_game *data, char *name, sfVector2i pos);
void destroy_button(data_game *data);
void button_set_tag(data_game *data, char *name, button_tag_t tag);
void button_add_text(data_game *data, char *name, char *title);
void button_add_text(data_game *data, char *name, char *title);
void button_add_action(data_game *data, char *name, void (*action)(data_game *));
void button_set_text(data_game *data, char *name, char *title);
void button_set_press_position(data_game *data, char *name, sfVector2f new_pos);

#endif //MUL_MY_RUNNER_2019_BUTTON_H
