/*
** EPITECH PROJECT, 2021
** B-PSU-402-LYN-4-1-strace-bogdan.guillemoles
** File description:
** tests_tools
*/

#include <criterion/criterion.h>
#include "ftrace.h"
#include "tools.h"
#include "display_private.h"

Test(tabgen, generate_a_tab)
{
    char **tab = tabgen("this is a string", ' ');

    cr_assert_neq(tab, 0);
    cr_assert_str_eq(tab[0], "this");
    cr_assert_str_eq(tab[2], "a");
    free_tab(tab);
}

Test(tabgen, prevent_crashes)
{
    cr_assert_eq(tabgen(0x0, 'a'), 0);
}

Test(append, better_strcat)
{
    cr_assert_str_eq(append("lol", " gamer"), "lol gamer");
}

Test(extract_string, extract_a_string)
{
    char **tab = tabgen("wow gamer:epic fortnite:haha yeet", ':');

    cr_assert_str_eq(extract_string(tab, "epic"), " fortnite");
    cr_assert_eq(get_nb_lines(tab), 3);
}

Test(append, append_string)
{
    char *s1 = strdup("yeet");
    char *s2 = strdup("lol");
    char *nullstr = 0x0;

    cr_assert_str_eq(append(s1, s2), "yeetlol");
    cr_assert_str_eq(append(s1, nullstr), "yeet");
    cr_assert_str_eq(append(nullstr, s2), "lol");
}

Test(append_c, append_char)
{
    cr_assert_str_eq(append_c(strdup("lol"), 'v'), "lolv");
    cr_assert_str_eq(append_c(0x0, 'a'), "a");
}

Test(read_str, read_str_array)
{
    user_input_t bin = load_default_settings();
    int ac = 2;
    char **av = tabgen("ftrace unit_tests", ' ');

    retrieve_user_options(ac, av, &bin);
    cr_assert_eq(read_str_array(bin, 0), NULL);
    cr_assert_eq(read_str(bin, 0), NULL);
    cr_assert_eq(read_str_array(bin, 1125), NULL);
    cr_assert_eq(read_str(bin, 1150), NULL);
}
