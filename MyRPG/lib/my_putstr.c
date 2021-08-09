/*
** EPITECH PROJECT, 2019
** mprime str
** File description:
** zfzef
*/

void my_putchar(char);

int my_putstr(char const *str)
{
    int x = 0;

    while (str[x] != '\0')
    {
        my_putchar(str[x]);
        x++;
    }
}
