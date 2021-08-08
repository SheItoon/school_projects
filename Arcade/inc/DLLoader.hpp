/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** DLLoader.hpp
*/

#ifndef DLLOADER
#define DLLOADER

#include <string>
#include <memory>

namespace arc
{
    class DLLoader
    {
        void *m_library;
        void *(*m_entry)();
    public:
        explicit DLLoader(const std::string &path);
        DLLoader(DLLoader &&);
        ~DLLoader();
        template <typename T>
        T* getInstance();
    }; // class DLLoader
} // namespace arc

#include "DLLoader.inl"

#endif //DLLOADER
