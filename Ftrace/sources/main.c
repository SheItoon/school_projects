/*
** EPITECH PROJECT, 2021
** B-PSU-402-LYN-4-1-strace-bogdan.guillemoles
** File description:
** main
*/

#include "ftrace.h"
#include <stdio.h>
#include "tools.h"
#include "display.h"
#include "tracer.h"
#include <string.h>

int main(int ac, char **av)
{
    user_input_t usr = load_default_settings();
    int status = 0;

    if (retrieve_user_options(ac, av, &usr) == ERROR)
        return ERROR;
    status = setup_ptrace(usr);
    elf_end(usr.elf_object);
    return status;
}
