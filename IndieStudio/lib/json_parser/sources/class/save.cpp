/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** save.cpp
*/

#include "Data.hpp"

void jsnp::Data::save(const std::string& filename)
{
    std::ofstream fstream(filename);

    fstream << m_object;
}