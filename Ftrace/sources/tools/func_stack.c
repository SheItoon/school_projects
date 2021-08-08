/*
** EPITECH PROJECT, 2021
** ftrace
** File description:
** func_stack
*/

#include "ftrace.h"
#include "tools.h"
#include <string.h>

inline func_stack_t *pop_first(func_stack_t *stack)
{
    func_stack_t *result = 0x0;

    if (!stack)
        return 0x0;
    free(stack->function_name);
    result = stack->next;
    free(stack);
    return result;
}

func_stack_t *append_func(func_stack_t *stack, char const *name)
{
    func_stack_t *new = malloc(sizeof(func_stack_t));

    new->function_name = strdup(name);
    new->next = stack;
    return new;
}
