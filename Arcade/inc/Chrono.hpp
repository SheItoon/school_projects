/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Chrono.hpp
*/

#ifndef __CHRONO_H__
#define __CHRONO_H__

#include <chrono>

namespace arc
{

    class Chrono
    {

        private:
            std::chrono::time_point<std::chrono::steady_clock> m_start;
            std::chrono::time_point<std::chrono::steady_clock> m_tour;
            std::chrono::time_point<std::chrono::steady_clock> m_end;
            bool m_isRuning;

        public:
            enum ctorState { Wait, Lauch };
            Chrono();
            Chrono(ctorState state);
            ~Chrono() = default;

            void start();
            void stop();
            void tour();
            double getElapsedTime();
            double getTotalTime();

    }; // class Chrono

    #include "Chrono.inl"

} // namespace arc


#endif // __CHRONO_H__