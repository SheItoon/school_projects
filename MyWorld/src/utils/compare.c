/*
** EPITECH PROJECT, 2019
** compare.c
** File description:
** want to compare an str?
*/

int compare(char const *str1, char const *str2)
{
    for (int i = 0; str1[i] != '\0'; i++) {
            if (str1[i] != str2[i])
                return (0);
    }
    return (1);
}