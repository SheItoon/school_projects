/*
** EPITECH PROJECT, 2019
** compteur lettre
** File description:
** zrar
*/

int my_strlen(char const *str)
{
    int x = 0;

    while (str[x] != '\0') {
        x++;
    }
    return (x);
}
