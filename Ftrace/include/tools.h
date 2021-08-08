/*
** EPITECH PROJECT, 2021
** TOOLS_H
** File description:
** tools
*/

#ifndef TOOLS_H
#define TOOLS_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct function_stack_s func_stack_t;
typedef struct function_stack_s
{
    char *function_name;
    func_stack_t *next;
} func_stack_t;

// func_stack.c
func_stack_t * pop_first(func_stack_t *);
func_stack_t * append_func(func_stack_t *, char const *);

//tabgen.c
char **tabgen(const char *string, char separator);

//tab_utils.c
char **add_slashes(char **tab);
int get_nb_lines(char **);
void free_tab(char **);
char *extract_string(char **tab, char *string);

//str_funcs.c
char *get_last(char *, char);

//utils.c
bool is_calling_function(unsigned short);
bool is_exiting_function(unsigned short);
char *append_c(char *s, char c);
bool is_syscall(unsigned short);
char *append(char *s, char *);

#endif /* TOOLS_H */
