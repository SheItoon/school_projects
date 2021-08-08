/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Error.hpp
*/

#ifndef __SHIPWRECK_ERROR_HPP__
#define __SHIPWRECK_ERROR_HPP__

#include <stdexcept>

namespace sw
{

    class Error :
        public std::runtime_error
    {

        protected:
            const std::string m_code;
            const std::string m_message;

        public:
            Error() = delete;
            Error(Error const&) = delete;
            Error(Error &&) = delete;
            Error& operator=(Error const &) = delete;
            Error& operator=(Error&&) = delete;

            Error(const std::string &message, const std::string &code);
            ~Error() override = default;
            [[nodiscard]] const std::string &getMessage() const;
            [[nodiscard]] const std::string &getCode() const;

    }; // class Error

} // namespace sw

std::ostream &operator<<(std::ostream &s, const sw::Error &error);

#endif // __SHIPWRECK_ERROR_HPP__
