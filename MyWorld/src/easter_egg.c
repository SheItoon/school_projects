/*
** EPITECH PROJECT, 2020
** ee
** File description:
** ee
*/

#include "my_world.h"
#include "normal.h"

//do not ever set pitch at 0.1 on all star
void play_shrek(void *info)
{
    (void)info;
    sfMusic *yolo = sfMusic_createFromFile("rsc/easter_egg.ogg");
    float yee = (float)((rand() % 5) / 2.3);

    sfMusic_setLoop(yolo, sfTrue);
    sfMusic_setPitch(yolo, yee);
    sfMusic_play(yolo);
}

void my_putshrek(void)
{
    sfThread *yolo = sfThread_create(&play_shrek, NULL);

    sfThread_launch(yolo);
}

int parse_shrek(data_game *data, char key)
{
    static int i = 0;

    switch (key) {
    case 's':
    case 'h':
    case 'r':
    case 'e':
    case 'k': add_to_string(data, key), i++;
        break;
    default:
        return(reset(data), i = 0, 1);
    }
    return (0);
}
