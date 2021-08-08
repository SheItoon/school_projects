/*
** EPITECH PROJECT, 2021
** ray_color.hpp
** File description:
** ray_color.hpp
*/

#ifndef COLOR
#define COLOR

#include "raylib.h"

namespace ray
{

    class RColor
    {
    private:
        Color m_color;
    public:
        RColor();
        ~RColor() = default;
        void setColor(int red, int blue, int green, int alpha);
        void setColor(Color color);
        [[nodiscard]] Color getColor() const;
    }; // class RColor

} // namespace ray

#endif //COLOR
