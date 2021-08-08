/*
** EPITECH PROJECT, 2021
** ftrace
** File description:
** tests_elf
*/

#include "ftrace.h"
#include "tools.h"
#include <criterion/criterion.h>

Test(get_elf_object, get_elf)
{
    user_input_t usr = load_default_settings();
    user_input_t yeet = load_default_settings();

    cr_assert_eq(get_elf_object("yeet", &yeet), false);

    cr_assert_eq(get_elf_object("./tests/bin/.default", &usr), true);
    cr_assert_neq(usr.elf_object, 0x0);
    cr_assert_eq(usr.execve_started, false);
}

Test(append_func, appendfunc)
{
    func_stack_t *func = 0x0;

    func = append_func(func, "yeet");
    cr_assert_str_eq(func->function_name, "yeet");
    func = append_func(func, "marlo");
    cr_assert_str_eq(func->next->function_name, "yeet");
    func = pop_first(func);
    cr_assert_str_eq(func->function_name, "yeet");
}
