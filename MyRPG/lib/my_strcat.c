/*
** EPITECH PROJECT, 2019
** addition chaine
** File description:
** miaou
*/

int my_strlen(char const*);

char *my_strcat(char *dest,char const *src)
{
    int x = 0;
    int a;
    int b;
     
    a = my_strlen(src);
    b = my_strlen(dest);
    while (src[x] != '\0') {
        dest[b + x] = src[x];
        x++;
    }
    return (dest);
}
