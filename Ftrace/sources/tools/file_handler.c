/*
** EPITECH PROJECT, 2021
** strace
** File description:
** file_handler
*/

#include "ftrace.h"
#include <stdio.h>

void open_outfile_if_needed(user_input_t *options)
{
    FILE *new_stream = 0x0;

    if (options->output_options & OUTPUT_TO_FILE) {
        new_stream = fopen(options->output_filename, "ab+");
        options->out = (!new_stream) ? stdout : new_stream;
    } else options->out = stdout;
}

void close_outfile_if_needed(user_input_t *options)
{
    if (options->output_options & OUTPUT_TO_FILE)
        fclose(options->out);
}
