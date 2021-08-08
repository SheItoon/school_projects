/*
** EPITECH PROJECT, 2021
** ftrace
** File description:
** load_from_register
*/

#include "display.h"
#include "display_private.h"
#include "ftrace.h"
#include <sys/ptrace.h>
#include <ctype.h>
#include <string.h>

char *read_str(user_input_t usr, unsigned long long reg)
{
    register char c = -1;
    register size_t loop_ctr = -1;
    register size_t ctr = -1;
    register char *res = malloc(((ARR_SIZE << 1) + 1) * sizeof(char));

    if (!res)
        return 0x0;
    while (c != 0 && ++loop_ctr < ARR_SIZE) {
        if ((c = (char)ptrace(PTRACE_PEEKDATA, usr.ppid, reg++) == -1))
            return 0x0;
        if (isprint(c) || c == '\t' || c == '\n')
            res[++ctr] = c;
    }
    res[++ctr] = 0;
    if (ctr == ARR_SIZE) {
        res = realloc(res, sizeof(char) * (ARR_SIZE + 5));
        res = strcat(res, "...");
    }
    return res;
}

char **read_str_array(user_input_t usr, unsigned long long reg)
{
    long tmp = -1;
    long *addresses = malloc(sizeof(long) * (ARR_SIZE + 1));
    size_t array_size = -1;
    char **result = 0x0;

    if (!addresses)
        return 0x0;
    while (tmp != 0 && ARR_SIZE > ++array_size) {
        if ((tmp = ptrace(PTRACE_PEEKDATA, usr.ppid, reg++)) == -1)
            return 0x0;
        addresses[array_size] = tmp;
    }
    result = malloc(sizeof(char *) * (array_size + 1));
    if (!result)
        return 0x0;
    else result[array_size] = 0x0;
    for (size_t ctr = -1; ++ctr < array_size; )
        result[ctr] = read_str(usr, addresses[ctr]);
    return result;
}
