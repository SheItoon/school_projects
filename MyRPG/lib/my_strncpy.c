/*
** EPITECH PROJECT, 2019
** zef
** File description:
** ze
*/

char *my_strncpy(char *dest,char const *src ,int n)
{
    while (n >= 0)
    {
        dest[n] = src[n];
        n--;
    }
    return (dest);
}
