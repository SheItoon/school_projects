/*
** EPITECH PROJECT, 2019
** another one
** File description:
** aaaaaaaaaaa
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_hunter.h"
#include <time.h>

char *get_score(int nbr)
{
    int len = number_digits(nbr);
    char *result;

    result = malloc(sizeof(char) * len + 1); 
    result[len] = '\0';
    while (len--) {
        result[len] = nbr % 10 + '0';
        nbr /= 10;
    }
    return (result);
}

int number_digits(int nbr)
{
    int n = 1;
    int pow = 10;

    if (nbr < 0)
        nbr = -nbr;
    while (nbr >= pow) {
        n++;
        if (pow > 214748364)
            break;
        pow *= 10;
    }
    return (n);
}
