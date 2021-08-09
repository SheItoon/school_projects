/*
** EPITECH PROJECT, 2019
** rev
** File description:
** char * to char* 
*/

char *my_revstr(char *str)
{
    char rev;
    char rev2;
    int x = 0;
    int n = 0;
    int y = 0;

    while (str[x] != '\0') {
        x++;
    }
    if (x % 2 != 0)
        y = 1;
    while (n < (x + y) / 2) {
        rev = str[n];
        rev2 = str[x - n - 1];
        str[n] = rev2;
        str[x - n - 1] = rev;
        n++;
    }
    return (str);
}
