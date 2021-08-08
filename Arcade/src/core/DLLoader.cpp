/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** DLLoader.cpp
*/

#include <dlfcn.h>
#include <iostream>
#include "../../inc/DLLoader.hpp"

arc::DLLoader::DLLoader(const std::string &path) : m_library(nullptr), m_entry(nullptr)
{
    void *library = dlopen(path.c_str(), RTLD_LAZY);
    const char *error = dlerror();

    if (!library)
        throw (arc::Error(std::string("Library cannot be open: ") + error, "LIB001"));
    m_library = library;
    *(void **)(&m_entry) = dlsym(m_library, "entryPoint");
    if (!m_entry) {
        std::cerr << "Function cannot be found: " << dlerror() << std::endl;
        throw (arc::Error(std::string("Library doesn't have an entryPoint: ") + error, "LIB002"));
    }
}

arc::DLLoader::DLLoader(DLLoader && loader)
{
    m_library = loader.m_library;
    m_entry = loader.m_entry;
}

arc::DLLoader::~DLLoader()
{
    dlclose(m_library);
}