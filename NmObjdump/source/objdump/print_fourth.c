/*
** EPITECH PROJECT, 2021
** print
** File description:
** print
*/

#include <glob.h>
#include <stdio.h>
#include "objdump.h"

static void print_hex_val(unsigned char *section, size_t hsize, size_t idx)
{
    size_t i;

    for (i = idx; i < idx + 16 && i < hsize; i++) {
        if ((i - idx) % 4 == 0)
            printf(" ");
        printf("%02x", section[i]);
    }
    while (i < idx + 16) {
        if ((i - idx) % 4 == 0)
            printf(" ");
        printf("  ");
        i++;
    }
}

static void print_ascii_val(unsigned char *section, size_t hsize, size_t idx)
{
    size_t i;

    for (i = idx; i < idx + 16 && i < hsize; i++) {
        if (section[i] >= ' ' && section[i] <= '~')
            printf("%c", section[i]);
        else
            printf(".");
    }
    while (i < idx + 16) {
        printf(" ");
        i++;
    }
}

int print_hexa(unsigned char *section, size_t addr, size_t  size)
{
    int padding = 0;
    size_t value = addr + size;

    while (value) {
        value = value / 16;
        padding += 1;
    }
    if (padding < 4)
        padding = 4;
    for (size_t idx = 0; idx < size; idx += 16) {
        printf(" %0*lx", padding, addr + idx);
        print_hex_val(section, size, idx);
        printf("  ");
        print_ascii_val(section, size, idx);
        printf("\n");
    }
    return (0);
}
