/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** take_object.cpp
*/

#include <unordered_map>
#include <functional>

#include "Data.hpp"

jsnp::Object jsnp::Data::take_object(const std::string& file, int& ctr)
{
    jsnp::Object obj;

    while (file[ctr] && file[ctr] != '}') {
        if (file[ctr] == ':') {
            jsnp::Token token = take_token(file, ctr);
            obj.insert_back(token);
        }
        else
            ctr += 1;
    }
    ctr += 1;
    return (obj);
}