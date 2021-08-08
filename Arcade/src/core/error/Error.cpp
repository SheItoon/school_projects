/*
** EPITECH PROJECT, 2021
** Error.cpp.cc
** File description:
** Error.cpp.cc
*/

#include <string>
#include "../../../inc/Error.hpp"

arc::Error::Error(const std::string &message, const std::string &code) :
runtime_error(message),
m_code(code),
m_text(message)
{}

std::string arc::Error::getText() const
{
    return (m_text);
}

std::string arc::Error::getCode() const
{
    return (m_code);
}

std::ostream &operator<<(std::ostream &s, const arc::Error &error)
{
    s << std::string("[") << error.getCode() << std::string("]: ") << error.getText();
    return (s);
}