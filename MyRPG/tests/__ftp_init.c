/*
** EPITECH PROJECT, 2020
** hack
** File description:
** hack
*/

#include <criterion/criterion.h>
#include "hacker_stuff.h"

Test(ftp_init_login, Ftp_no_internet)
{
    cr_assert_arr_eq(ftp_init_login(), 1);
}

Test(ftp_init_login, Ftp_internet)
{
    cr_assert_arr_eq(ftp_init_login(), 0);
}