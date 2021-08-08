/*
** EPITECH PROJECT, 2021
** B-PSU-402-LYN-4-1-strace-bogdan.guillemoles
** File description:
** input_handling
*/

#include "ftrace.h"
#include <bits/getopt_core.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

user_input_t load_default_settings(void)
{
    user_input_t result = {
        .args = 0x0,
        .out = stdout,
        .output_filename = 0x0,
        .output_options = 0,
        .ppid = 0,
        .children = 0x0,
        .stack = 0x0,
        .elf_object = 0x0,
        .is_32_bits = false,
        .execve_started = false,
        .function_symbols = 0x0
    };

    return result;
}

static char *get_complete_path_if_executable(char *cmd, char **paths)
{
    char *result = 0x0;
    struct stat st;

    for (int i = 0; paths[i] != 0x0; i++) {
        result = append(paths[i], cmd);
        if (stat(result, &st) != -1 && st.st_mode & S_IRUSR)
            return result;
        free(result);
    }
    free_tab(paths);
    return 0x0;
}

static char *get_command_path(char *cmd)
{
    char *env_path = 0x0;
    char **paths = 0x0;
    struct stat st;
    char *result = cmd[0] != '.' && cmd[0] != '/' ? append("./", cmd) : cmd;

    if (stat(result, &st) != -1 && st.st_mode & S_IRUSR)
        return result;
    env_path = extract_string(environ, "PATH=");
    paths = add_slashes(tabgen(env_path, ':'));
    free(env_path);
    return get_complete_path_if_executable(cmd, paths);
}

static int check_if_command_provided(int ac, char **av,
int ind, user_input_t *usr)
{
    usr->args = (ind < ac) ? &av[ind] : usr->args;
    if (usr->args) {
        usr->args[0] = get_command_path(usr->args[0]);
        if (!usr->args[0] || !get_elf_object(av[ind], usr))
        return ERROR;
    } else if (!usr->args)
        return ERROR;
    return SUCCESS;
}

int retrieve_user_options(int ac, char **av, user_input_t *binary)
{
    int c = 0;

    while ((c = getopt(ac, av, "+:sfo:")) != -1) {
        switch (c) {
            case 's': binary->output_options |= DISPLAY_WITHOUT_HEX;
                break;
            case 'f': binary->output_options |= FOLLOW_FORKS;
                break;
            case 'o':
                binary->output_options |= OUTPUT_TO_FILE;
                binary->output_filename = strdup(optarg);
                break;
            case '?': return ERROR;
        }
    }
    return check_if_command_provided(ac, av, optind, binary);
}
