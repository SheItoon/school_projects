/*
** EPITECH PROJECT, 2020
** my_isnum
** File description:
** numbre are numbre ?
*/

int my_isnum(char C)
{
    if (C > 57 || C < 48)
        return (1);
    return (0);
}
