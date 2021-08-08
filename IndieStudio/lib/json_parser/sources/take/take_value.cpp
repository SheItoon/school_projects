/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** take_value.cpp
*/

#include "Data.hpp"

static std::string take_string(const std::string& file, int& ctr)
{
    std::string str;

    ctr += 1;
    while (file[ctr] && file[ctr] != '"') {
        str.push_back(file[ctr]);
        ctr += 1;
    }
    ctr += 1;
    return (str);
}

static void take_null(const std::string& file, int& ctr)
{
    char cpy[5];
    unsigned len = file.copy(cpy, 4, ctr);

    cpy[len] = '\0';
    if (std::string(cpy) != "null")
        throw std::exception();
    ctr += 4;
}

static bool take_boolean(const std::string& file, int& ctr)
{
    char cpy[6];
    unsigned len = file.copy(cpy, 5, ctr);

    cpy[len] = '\0';
    if (std::string(cpy) == "true,")
        return (ctr += 4, true);
    if (std::string(cpy) == "false")
        return (ctr += 5, false);
    throw std::exception();
}

static int take_number(const std::string& file, int& ctr)
{
    int number = std::atoi(&file[ctr]);

    if (file[ctr] == '-')
        ctr += 1;
    while (file[ctr] && '0' <= file[ctr] && file[ctr] <= '9')
        ctr += 1;
    return (number);
}

jsnp::Value jsnp::Data::take_value(const std::string& file, int& ctr)
{
    jsnp::Value value;

    switch (file[ctr]) {
        case '[':
            value = jsnp::Value(take_array(file, ctr));
            break;
        case '{':
            value = jsnp::Value(take_object(file, ctr));
            break;
        case '"':
            value = jsnp::Value(take_string(file, ctr));
            break;
        case 'n':
            take_null(file, ctr);
            value = jsnp::Value();
            break;
        case 't':
        case 'f':
            value = jsnp::Value(take_boolean(file, ctr));
            break;
        default:
            value = jsnp::Value(take_number(file, ctr));
            break;
    }
    if (file[ctr] == ',')
        ctr += 1;
    return (value);
}