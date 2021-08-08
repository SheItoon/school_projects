/*
** EPITECH PROJECT, 2021
** utils
** File description:
** utils
*/

#include "libmemory.h"
#include <unistd.h>


size_t convert_paging(size_t target)
{
    return ((target - 1) / 8 * 8 + 8);
}
