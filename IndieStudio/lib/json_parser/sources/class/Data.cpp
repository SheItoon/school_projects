/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** jsnp_parser.cpp
*/

#include "Data.hpp"

jsnp::Data::Data()
    :   m_object()
{}

jsnp::Data::Data(const std::string& filename)
    :   m_object()
{
    parse(filename);
}