/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** take_token.cpp
*/

#include "Data.hpp"

jsnp::Token jsnp::Data::take_token(const std::string& file, int& ctr)
{
    jsnp::Token token;

    ctr -= 2;
    for (int i = 0; file[ctr - i] != '"'; i += 1)
        token.first.push_back(file[ctr - i]);
    std::reverse(token.first.begin(), token.first.end());
    ctr += 3;
    token.second = take_value(file, ctr);
    return (token);
}