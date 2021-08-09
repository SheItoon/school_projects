/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** rpg
*/

#include <SFML/Graphics.h>
#include <SFML/Network.h>
#include <SFML/Window.h>
#include "my.h"
#include <math.h>
#include <stdlib.h>
#include "hacker_stuff.h"
#include <stdio.h>

int my_strcmp(const char *str1, const char *str2)
{
    int i = 0;

    if (str1 == NULL || str2 == NULL)
        return (-1);
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i])
                return (str1[i] - str2[i]);
        i++;
    }
    return (0);
}

int check_connection(void)
{
    sfIpAddress self = sfIpAddress_getPublicAddress(sfSeconds(50));

    srand(0);
    return (my_strcmp(self.address, "0.0.0.0") ? 0 : 1);
}
