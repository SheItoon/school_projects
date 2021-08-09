/*
** EPITECH PROJECT, 2019
** get_next_line project
** File description:
** get_next_line
*/

#include "get_next_line.h"

char *get_old(res_s *result, params_s *params);

static char *my_strncpy(char *dest, char *src, int n)
{
    int i;

    for (i = 0; src[i] != '\0' && i < n; i++)
        dest[i] = src[i];
    if (n < i)
        dest[i] = '\0';
    return (dest);
}

static res_s *init(params_s **params)
{
    static int check = 0;
    res_s *tmp = NULL;

    if (check == 0) {
        *params = malloc(sizeof(params_s));
        (*params)->buff = malloc(sizeof(char) * READ_SIZE);
        if ((*params)->buff == NULL)
            return (NULL);
        (*params)->bytes = 0;
        (*params)->start = 0;
        check++;
    }
    tmp = malloc(sizeof(res_s));
    tmp->res = NULL;
    tmp->check = 0;
    tmp->oldsize = 0;
    tmp->newres = NULL;
    return (tmp);
}

static int my_strlen(char *str)
{
    int i;

    for (i = 0; str[i]; i++);
    return (i);
}

char *get_next_line(int fd)
{
    static params_s *params = NULL;
    res_s *result = init(&params);

    if (result == NULL)
        return (NULL);
    while (1) {
        if (params->bytes <= params->start) {
            params->start = 0;
            params->bytes = read(fd, params->buff, READ_SIZE);
            if (params->bytes <= 0)
                return ((params->bytes == -1) ? NULL : result->res);
            result->check = 0;
        }
        if (params->buff[params->start + result->check] == '\n')
            return (result->res = get_old(result, params));
        result->res = (params->start + result->check == params->bytes - 1) ?
        get_old(&(res_s){result->check + 1, result->res},
        params) : result->res;
        result->check++;
    }
}

char *get_old(res_s *result, params_s *params)
{
    result->oldsize = (result->res != NULL) ? my_strlen(result->res) : 0;
    result->newres = malloc(sizeof(char) *
    (result->oldsize + result->check + 1));
    (result->res != NULL) ? my_strncpy(result->newres, result->res,
    result->oldsize) :
    my_strncpy(result->newres, "\0", result->oldsize);
    result->newres[result->oldsize + result->check] = '\0';
    my_strncpy(result->newres + result->oldsize, params->buff +
    params->start, result->check);
    params->start += (result->check + 1);
    return (result->newres);
}
