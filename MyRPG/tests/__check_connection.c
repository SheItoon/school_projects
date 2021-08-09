/*
** EPITECH PROJECT, 2020
** check
** File description:
** check
*/

#include <criterion/criterion.h>
#include "hacker_stuff.h"

Test(check_connection, No_internet)
{
    cr_assert_arr_eq(check_connection(), 1);
}

Test(check_connection, Internet)
{
    cr_assert_arr_eq(check_connection(), 0);
}