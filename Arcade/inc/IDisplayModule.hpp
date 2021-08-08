/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** IDisplayModule.hpp
*/

#ifndef __IDISPLAYMODULE_HPP__
#define __IDISPLAYMODULE_HPP__

#include <string>

#include "Color.hpp"
#include "Vector.hpp"
#include "Keyboard.hpp"

namespace arc
{

    class IDisplayModule
    {

        public:
            virtual ~IDisplayModule() = default;
            virtual std::string getName() const = 0;

            virtual void clearWindow() = 0;
            virtual void displayWindow() = 0;
            virtual void checkEvent() = 0;
            virtual bool isOk() = 0;
            virtual bool getKeyDown(Keyboard key) = 0;

            virtual void drawText(const std::string& text, int characterSize, Color color, Vector<float> position) = 0;
            virtual void drawSquare(int size, Color color, Vector<float> position) = 0;

    }; // class IDisplayModule

} // namespace arc

#endif // __IDISPLAYMODULE_HPP__