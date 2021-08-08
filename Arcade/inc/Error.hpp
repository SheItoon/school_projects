/*
** EPITECH PROJECT, 2021
** Error.hpp.h
** File description:
** Error.hpp.h
*/

#ifndef ERROR
#define ERROR

#include <stdexcept>

namespace arc
{
    class Error : public std::runtime_error
    {
        std::string m_code;
        std::string m_text;
        public:
            Error() = delete;
            Error(const std::string &message, const std::string &code);
            ~Error() = default;
            std::string getCode() const;
            std::string getText() const;
    }; // class Error
} // namespace arc

std::ostream &operator<<(std::ostream &s, const arc::Error &error);

#endif //ERROR
