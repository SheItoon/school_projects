/*
** EPITECH PROJECT, 2021
** B-PSU-402-LYN-4-1-strace-bogdan.guillemoles
** File description:
** tests_parser
*/

#include <criterion/criterion.h>
#include "ftrace.h"
#include <stdio.h>

Test(retrieve_user_options, standard_scenario)
{
    user_input_t bin = load_default_settings();
    int ac = 2;
    char **av = tabgen("ftrace unit_tests", ' ');

    cr_assert_eq(retrieve_user_options(ac, av, &bin), SUCCESS);
    cr_assert_eq(bin.output_options, 0);
    cr_assert_eq(bin.output_filename, 0x0);
    cr_assert_str_eq(bin.args[0], "./unit_tests");
}

Test(retrieve_user_options, add_some_options)
{
    user_input_t bin = load_default_settings();
    char **av = tabgen("ftrace -f -s -o example ls", ' ');
    int ac = 6;

    cr_assert_eq(retrieve_user_options(ac, av, &bin), SUCCESS);
    cr_assert_eq(bin.output_options & FOLLOW_FORKS, FOLLOW_FORKS);
    cr_assert_eq(bin.output_options & DISPLAY_WITHOUT_HEX,
    DISPLAY_WITHOUT_HEX);
    cr_assert_eq(bin.output_options & OUTPUT_TO_FILE, OUTPUT_TO_FILE);
    cr_assert_str_eq(bin.output_filename, "example");
    cr_assert_str_eq(bin.args[0], "/usr/bin/ls");
    cr_assert_eq(bin.args[1], 0x0);
}

Test(retrieve_user_options, check_path_handling)
{
    user_input_t bin = load_default_settings();
    char **av = tabgen("ftrace -f -s -o example /usr/bin/ls", ' ');
    int ac = 6;

    cr_assert_eq(retrieve_user_options(ac, av, &bin), SUCCESS);
    cr_assert_eq(bin.output_options & FOLLOW_FORKS, FOLLOW_FORKS);
    cr_assert_eq(bin.output_options & DISPLAY_WITHOUT_HEX,
    DISPLAY_WITHOUT_HEX);
    cr_assert_eq(bin.output_options & OUTPUT_TO_FILE, OUTPUT_TO_FILE);
    cr_assert_str_eq(bin.output_filename, "example");
    cr_assert_str_eq(bin.args[0], "/usr/bin/ls");
    cr_assert_eq(bin.args[1], 0x0);
}

Test(retrieve_user_options, some_options)
{
    user_input_t bin = load_default_settings();
    char **av = tabgen("ftrace -f unit_tests arg arg2", ' ');
    int ac = 4;

    cr_assert_eq(retrieve_user_options(ac, av, &bin), SUCCESS);
    cr_assert_eq(bin.output_options & FOLLOW_FORKS, FOLLOW_FORKS);
    cr_assert_eq(bin.output_options & DISPLAY_WITHOUT_HEX, 0);
    cr_assert_eq(bin.output_options & OUTPUT_TO_FILE, 0);
    cr_assert_eq(bin.output_filename, 0x0);
    cr_assert_str_eq(bin.args[0], "./unit_tests");
    cr_assert_str_eq(bin.args[1], "arg");
    cr_assert_str_eq(bin.args[2], "arg2");
}

Test(retrieve_user_options, no_options)
{
    user_input_t bin = load_default_settings();
    char **av = tabgen("ftrace", ' ');
    int ac = 1;

    cr_assert_eq(retrieve_user_options(ac, av, &bin), ERROR);
}

Test(retrieve_user_options, wrong_opt)
{
    user_input_t bin = load_default_settings();
    int ac = 3;
    char **av = tabgen("ftrace -a lol", ' ');

    cr_assert_eq(retrieve_user_options(ac, av, &bin), ERROR);
}

Test(retrieve_user_options, arg_ls)
{
    user_input_t bin = load_default_settings();
    int ac = 2;
    char **av = tabgen("ftrace ls", ' ');

    cr_assert_eq(retrieve_user_options(ac, av, &bin), SUCCESS);
}

Test(retrieve_user_options, unknown_cmd)
{
    user_input_t bin = load_default_settings();
    int ac = 2;
    char **av = tabgen("ftrace yeet", ' ');

    cr_assert_eq(retrieve_user_options(ac, av, &bin), ERROR);
}

Test(elf_file, valid_elf_file)
{
    user_input_t bin = load_default_settings();
    int ac = 2;
    char **av = tabgen("ftrace ./unit_tests", ' ');

    cr_assert_eq(retrieve_user_options(ac, av, &bin), SUCCESS);
}

Test(elf_file, not_elf_file)
{
    user_input_t bin = load_default_settings();
    int ac = 2;
    char **av = tabgen("ftrace Makefile", ' ');

    cr_assert_eq(retrieve_user_options(ac, av, &bin), ERROR);
}
