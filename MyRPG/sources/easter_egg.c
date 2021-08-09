/*
** EPITECH PROJECT, 2020
** ee
** File description:
** ee
*/

#include <SFML/Audio.h>
#include <SFML/System.h>
#include "normal.h"

//do not ever set pitch at 0.1 on all star
void play_shrek(void *info)
{
    (void)info;
    sfMusic *yolo = sfMusic_createFromFile("resources/musics/easter_egg.ogg");
    float yee = (float)((rand() % 5) / 2.3);

    sfMusic_setPosition(yolo, (sfVector3f) { 10 + rand() % 80,
    rand() % 40, 0});
    sfMusic_setMinDistance(yolo, 30);
    sfMusic_setAttenuation(yolo, 20);
    sfMusic_setLoop(yolo, sfTrue);
    sfMusic_setPitch(yolo, yee);
    sfMusic_play(yolo);
}

void my_putshrek(void)
{
    sfThread *yolo = sfThread_create(&play_shrek, NULL);

    sfThread_launch(yolo);
}

int parse_shrek(combo_t *data, char key)
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
