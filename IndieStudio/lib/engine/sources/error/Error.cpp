/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Error.cpp
*/

#include <iostream>
#include "error/Error.hpp"

sw::Error::Error(const std::string &message, const std::string &code) :
std::runtime_error(message), m_code(code), m_message(message)
{}

const std::string &sw::Error::getMessage() const
{
    return (m_message);
}

const std::string & sw::Error::getCode() const
{
    return (m_code);
}

std::ostream &operator<<(std::ostream &s, const sw::Error &error)
{
    s << std::string("[") << error.getCode() << std::string("]: ") << error.getMessage();
    return (s);
}