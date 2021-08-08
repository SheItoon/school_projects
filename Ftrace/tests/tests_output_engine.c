/*
** EPITECH PROJECT, 2021
** ftrace
** File description:
** tests_output_engine
*/

#include <bits/types/siginfo_t.h>
#include <criterion/criterion.h>
#include <signal.h>
#include <stdio.h>
#include "display.h"
#include "ftrace.h"
#include "tools.h"
#include "display_private.h"

// for these tests, we simply test if it doesn't crash
// as they will be tested more in depth by the functionnal tests
Test(open_outfile_if_needed, open_and_close)
{
    user_input_t input = load_default_settings();

    open_outfile_if_needed(&input);
    input.output_filename = strdup("out");
    input.output_options |= OUTPUT_TO_FILE;
    open_outfile_if_needed(&input);
    close_outfile_if_needed(&input);
}

Test(display, simple_display)
{
    user_input_t user = load_default_settings();

    user.output_filename = strdup("out");
    user.output_options |= OUTPUT_TO_FILE;
    open_outfile_if_needed(&user);
    cr_assert_eq(display(user, "[PTR] str as argument:%s\n", "arg"), SUCCESS);
    cr_assert_eq(display(user, "[PTR] numbers as argument:%d %l %u\n", -5,
    9999, 669), SUCCESS);
    cr_assert_eq(display(user, "[PTR] env:%a\n", environ), SUCCESS);
    user.output_options |= DISPLAY_WITHOUT_HEX;
    cr_assert_eq(display(user, "Simple string.\n"), SUCCESS);
    cr_assert_eq(display(user, "some pointer: %p\n", environ), SUCCESS);
    cr_assert_eq(display(user, "str as argument:%s\n", "arg"), SUCCESS);
    cr_assert_eq(display(user, "numbers as argument:%d %l %u\n", -5, 9999,
    669), SUCCESS);
    cr_assert_eq(display(user, "env:%a\n", environ), SUCCESS);
    cr_assert_eq(is_authorized_flag(','), false);
    close_outfile_if_needed(&user);
}

Test(display, display_tabs)
{
    user_input_t input = load_default_settings();
    char **zero = tabgen("", ' ');
    char **one = tabgen("lol", ' ');
    char **two = tabgen("lol yeet",  ' ');
    char **three = tabgen("lol yeet swag", ' ');

    input.output_options |= DISPLAY_WITHOUT_HEX;
    input.output_options |= OUTPUT_TO_FILE;
    input.output_filename = strdup("out");
    open_outfile_if_needed(&input);
    cr_assert_eq(display(input, "zero: %a\n", zero), SUCCESS);
    cr_assert_eq(display(input, "one: %a\n", one), SUCCESS);
    cr_assert_eq(display(input, "two: %a\n", two), SUCCESS);
    cr_assert_eq(display(input, "three: %a\n", three), SUCCESS);
    close_outfile_if_needed(&input);
}

Test(display_sig, display_signal)
{
    user_input_t usr = load_default_settings();
    siginfo_t *sig = malloc(sizeof(siginfo_t));

    usr.output_filename = strdup("out");
    usr.output_options |= OUTPUT_TO_FILE;
    cr_assert_eq(display_sig(usr, 0x0), ERROR);
    sig->si_signo = SIGSEGV;
    open_outfile_if_needed(&usr);
    cr_assert_eq(display_sig(usr, sig), SUCCESS);
    sig->si_signo = 12121212;
    cr_assert_eq(display_sig(usr, sig), SUCCESS);
    close_outfile_if_needed(&usr);
}

/*
Test(display_sys, display_syscall)
{
    
}
*/
