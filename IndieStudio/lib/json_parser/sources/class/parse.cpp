/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** parse.cpp
*/

#include <fstream>
#include <sstream>
#include <algorithm>

#include "Data.hpp"

static std::string read_file(const std::string& filename)
{
    if (filename.substr(filename.size() - 5, 5) != ".json")
        throw std::exception();

    std::ifstream fstream(filename);
    std::stringstream sstream;
    std::string result;

    if (!fstream) {
        std::ofstream newFile(filename);
        return ("");
    }
    sstream << fstream.rdbuf();
    result = sstream.str();
    return (result);
}

void jsnp::Data::clean_file(std::string& file)
{
    bool in_quote = false;

    for (unsigned ctr = 0; file[ctr]; ctr += 1) {
        if (file[ctr] == '"' && ctr != 0 && file[ctr - 1] != '\\')
            in_quote = !in_quote;
        if (!in_quote && std::isspace(file[ctr]) != 0) {
            file.erase(ctr, 1);
            ctr -= 1;
        }
    }
    file.erase(0, 1);
    file.erase(file.size() - 1, 1);
}

void jsnp::Data::parse(const std::string& filename)
{
    std::string file = read_file(filename);
    int ctr = 0;

    if (!file.empty())
        clean_file(file);
    m_object = take_object(file, ctr);
}