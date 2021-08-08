/*
** EPITECH PROJECT, 2021
** test
** File description:
** test
*/

#include <bits/types/siginfo_t.h>
#include <criterion/criterion.h>
#include "ftrace.h"
#include <stdio.h>
#include "tools.h"
#include "display.h"
#include "tracer.h"
#include <string.h>
#include <signal.h>

Test(setup_ptrace, setup)
{
    user_input_t bin = load_default_settings();
    int ac = 2;
    char **av = tabgen("ftrace unit_tests", ' ');
    
    retrieve_user_options(ac, av, &bin);
    cr_assert_eq(setup_ptrace(bin), SUCCESS);
}

Test(setup_ptrace, crash, .signal = SIGSEGV)
{
    user_input_t bin = {0};

    setup_ptrace(bin);
}
