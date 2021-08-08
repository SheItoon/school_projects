/*
** EPITECH PROJECT, 2021
** B-PSU-402-LYN-4-1-strace-bogdan.guillemoles
** File description:
** utils
*/

#include "ftrace.h"
#include <strings.h>
#include <string.h>
#include <stdlib.h>

bool is_exiting_function(unsigned short code)
{
    unsigned short tmp_value = 0xFF & code;
    size_t ctr = -1;
    unsigned short exit_codes[] = {
        0xC3, 0x0
    };

    while (exit_codes[++ctr] != 0x0) {
        if (tmp_value == exit_codes[ctr])
            return true;
    }
    return false;
}

inline bool is_syscall(unsigned short code)
{
    return CALLING_SYSCALL(code);
}

char *append_c(char *s, char c)
{
    char *result = 0x0;
    int size_s = 0;

    if (!s || !(*s)) {
        result = malloc(sizeof(char) * 2);
        if (!result)
            return 0x0;
        result[0] = c;
        result[1] = 0;
        return result;
    }
    size_s = strlen(s);
    result = malloc(sizeof(char) * (size_s + 2));
    if (!result)
        return s;
    result = strcpy(result, s);
    result[size_s] = c;
    result[size_s + 1] = 0;
    free(s);
    return result;
}

char *append(char *s1, char *s2)
{
    int malloc_size = 0;
    char *new_str = 0x0;

    if ((!s1 || !(*s1)) || (!s2 || !(*s2))) {
        if (!s1 || !(*s1))
            return s2;
        else return s1;
    }
    malloc_size = strlen(s1) + strlen(s2);
    new_str = malloc(sizeof(char) * (malloc_size + 1));
    bzero(new_str, malloc_size);
    if (new_str != 0x0) {
        new_str[0] = '\0';
        new_str = strcpy(new_str, s1);
        new_str = strcat(new_str, s2);
    } else return 0x0;
    return new_str;
}
