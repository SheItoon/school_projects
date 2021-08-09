/*
** EPITECH PROJECT, 2019
** putchae
** File description:
** tres tres util
*/

#include<unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
