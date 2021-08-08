/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** take_array.cpp
*/

#include "Data.hpp"

jsnp::Array jsnp::Data::take_array(const std::string& file, int& ctr)
{
    jsnp::Array array;

    ctr += 1;
    while (file[ctr] && file[ctr] != ']') {
        jsnp::Value value = take_value(file, ctr);
        array.insert_back(value);
    }
    ctr += 1;
    return (array);
}