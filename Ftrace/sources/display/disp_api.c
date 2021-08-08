/*
** EPITECH PROJECT, 2021
** ftrace
** File description:
** disp_api
*/

#include "display.h"
#include "display_private.h"
#include "ftrace.h"
#include "tools.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

static char *load_str_array_fmt(char **tab, char *result)
{
    int nb_lines = get_nb_lines(tab);

    switch (nb_lines) {
        case 0:
            snprintf(result, SIZE, "[ \"\" ]");
            break;
        case 1:
            snprintf(result, SIZE, "[ \"%s\" ]", tab[0]);
            break;
        case 2:
            snprintf(result, SIZE, "[ \"%s\", \"%s\" ]", tab[0], tab[1]);
            break;
        case 3:
            snprintf(result, SIZE, "[ \"%s\", \"%s\", \"%s\" ]", tab[0],
            tab[1], tab[2]);
            break;
        default: snprintf(result, SIZE, "%p /* %d vars */",
            tab, get_nb_lines(tab));
    }
    return result;
}

static char *disp_interp_flag(va_list ap, char *res, char flag)
{
    switch (flag) {
        case UNSIGNED:
            snprintf(res, SIZE, "%llu", va_arg(ap, unsigned long long));
            break;
        case NUMBER:
            snprintf(res, SIZE, "%d", va_arg(ap, int));
            break;
        case STR_ARRAY:
            res = load_str_array_fmt(va_arg(ap, char **), res);
            break;
        case STRING:
            snprintf(res, SIZE, "%s", va_arg(ap, char *));
            return res;
        case LONG:
            snprintf(res, SIZE, "%lld", va_arg(ap, long long));
            break;
        case STRUCT: case POINTER: default:
            snprintf(res, SIZE, "%p", va_arg(ap, void *));
    }
    return res;
}

static char *get_va_arg(user_input_t usr, va_list ap, char flag)
{
    char *res = malloc(sizeof(char) * (SIZE + 1));

    bzero(res, SIZE);
    if (!res)
        return 0x0;
    else if (usr.output_options & DISPLAY_WITHOUT_HEX)
        res = disp_interp_flag(ap, res, flag);
    else snprintf(res, SIZE, "%#llx", va_arg(ap, unsigned long long));
    return res;
}

int display(user_input_t user, char *str, ...)
{
    size_t str_size = (!str) ? 0 : strlen(str);
    size_t ctr = -1;
    va_list ap;
    char *to_display = 0x0;
    char *substr = 0x0;

    va_start(ap, str);
    while (++ctr < str_size) {
        if (str[ctr] == '%' && is_authorized_flag(str[ctr + 1])) {
            substr = get_va_arg(user, ap, str[++ctr]);
            if (!substr)
                return 0x0;
            to_display = append(to_display, substr);
        } else to_display = append_c(to_display, str[ctr]);
    }
    va_end(ap);
    fprintf(user.out, "%s", to_display);
    free(to_display);
    return SUCCESS;
}
