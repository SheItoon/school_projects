/*
** EPITECH PROJECT, 2021
** DLLoader.inl
** File description:
** DLLoader.inl
*/

#include "Error.hpp"

template <typename T>
T* arc::DLLoader::getInstance()
{
    auto *module = static_cast<T *>(m_entry());

    if (!module)
        throw (arc::Error("Cannot create an instance of the module!", "LIB003"));
    return (module);
}