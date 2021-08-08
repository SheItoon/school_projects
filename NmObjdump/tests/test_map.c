/*
** EPITECH PROJECT, 2021
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "map.h"
#include "nm.h"
#include <string.h>

Test(map, empty_map)
{
    cr_assert_eq(map_file(NULL), 84);
}

Test(nm_test, testing_various)
{
    char *test[] = {"./unit_tests", "unit_tests"};
    char *test2[] = {"./unit_tests", "tests/libmy.a"};
    char *test3[] = {"./unit_tests", "source/nm/nm.o"};
    char *test4[] = {"./unit_tests", ""};
    char *test5[] = {"./unit_tests", "unit"};
    char *test6[] = {"./unit_tests", "unit_test", "source/nm/nm.o"};
    char *test7[] = {"./unit_tests", "my_nm", "my_nm"};

    cr_assert_eq(nm_engine(2, test), 0);
    cr_assert_eq(nm_engine(2, test2), 0);
    cr_assert_eq(nm_engine(2, test3), 0);
    cr_assert_eq(nm_engine(1, test4), 84);
    cr_assert_eq(nm_engine(2, test5), 84);
    cr_assert_eq(nm_engine(3, test6), 84);
    cr_assert_eq(nm_engine(3, test7), 0);
}
