/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** count and return the char difference
*/

#include <unistd.h>

int my_strcmp(const char *str1, const char *str2)
{
    int	i = 0;

    if (str1 == NULL || str2 == NULL)
        return (-1);
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i])
	        return (str1[i] - str2[i]);
        i++;
    }
    return (0);
}
